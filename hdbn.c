#include <stdlib.h>
#include <stdio.h>

#define positif 1
#define negatif -1
#define neutre 0

void afficher_tableau(int tab[], int taille_tab){
    for (int i = 0 ; i < taille_tab ; i++){
        printf("%d |", tab[i]);
    }
    printf("\n");
}

void Codeur_HDBn(int data[], int taille_data, int n){
    int v = negatif;
    int b = positif;
    int dernier_i = negatif;
    int dernier_v = negatif;
    int dernier_b = positif;
    int res[taille_data];
    int tab_v[taille_data];
    int tab_b[taille_data];
    int i;
    int combien_de_0 = 0;

    for (i = 0 ; i < taille_data ; i ++){
        res[i] = neutre;
        tab_b[i] = neutre;
        tab_v[i] = neutre;
    }
    tab_v[0] = negatif;
    tab_b[0] = positif;

    for (i = 0 ; i < taille_data ; i++){
        if (data[i] == 0 && combien_de_0 < n){
            combien_de_0++;
        }
        else if(data[i] == 0 && combien_de_0 >= n){
            combien_de_0 = 0;
            if(dernier_v == positif){
                if (dernier_i == positif){
                    tab_v[i] = negatif;
                    tab_b[i-n] = negatif;
                    dernier_v = negatif;
                    dernier_b = negatif;
                    dernier_i = dernier_b;
                }
                else{
                    tab_v[i] = negatif;
                    dernier_v = negatif;
                }
            }
            else{
                if (dernier_i == positif){
                    tab_v[i] = positif;
                    dernier_v = positif;
                }
                else{
                    tab_v[i] = positif;
                    tab_b[i-n] = positif;
                    dernier_v = positif;
                    dernier_b = positif;
                    dernier_i = dernier_b;
                }
            }
        }
        else if (data[i] == 1){
            combien_de_0 = 0;
            if (dernier_i == positif){
                res[i] = negatif;
                dernier_i = negatif;
            }
            else if (dernier_i == negatif){
                res[i] = positif;
                dernier_i = positif;
            }
        }
    }
    printf("DATA : \n");
    afficher_tableau(data,taille_data);
    printf("V : \n");
    afficher_tableau(tab_v, taille_data);
    printf("B : \n");
    afficher_tableau(tab_b, taille_data);
    printf("res : \n");
    afficher_tableau(res, taille_data);

}
void afficheur_matrice_globale(float matrice_global[10][4],int sans_doublon){
  int i,j;
  printf("\n");

  for(i=0;i<sans_doublon;i++){
    for(j=0;j<4;j++){
      printf("%.3f | ", matrice_global[i][j]);
    }
    printf("\n");
  }
}

void Codeur_arithmetique(int tab_arithmetique[], int taille_tableau){
  float matrice_global[taille_tableau][4];
  int i,j;
  float borneInf=0,borneSup=0,intervalle=0;
  int sans_doublon=taille_tableau;
  for(i=0;i<10;i++){
    for(j=0;j<4;j++){
      matrice_global[i][j]=0;
    }
  }
  matrice_global[0][0]=tab_arithmetique[0];
  matrice_global[0][1]=1;
  for(i=1;i<10;i++){
    for(j=0;j<i;j++){
      if(matrice_global[j][0]==tab_arithmetique[i]){ // si on a deja le meme caractere
        matrice_global[j][1]+=1;
        sans_doublon-=1;

        }
      else{
        matrice_global[i][0]=tab_arithmetique[i];
        matrice_global[i][1]=1;
      }
    }
  }//fin for
  //printf("\n%d\n",sans_doublon);
//  afficheur_matrice_globale(matrice_global,sans_doublon);

  for(i=0;i<sans_doublon;i++){
    matrice_global[i][1]=  matrice_global[i][1]/taille_tableau;
  }
  afficheur_matrice_globale(matrice_global,sans_doublon);
  matrice_global[0][2]=0;
matrice_global[0][3]=matrice_global[0][1];
  for(i=1;i<sans_doublon;i++){
    matrice_global[i][2]=matrice_global[i-1][3];
    matrice_global[i][3]=matrice_global[i][1]+matrice_global[i][2];
  }
  afficheur_matrice_globale(matrice_global,sans_doublon);


  for(i=0;i<sans_doublon;i++){
    if(i>0){
      intervalle=borneSup-borneInf;
      borneSup=borneInf+(matrice_global[i][3]*intervalle);
      borneInf=borneInf+(matrice_global[i][2]*intervalle);
    }
    else{
      intervalle=matrice_global[0][3]-matrice_global[0][2];
      borneSup=matrice_global[0][3];
      borneInf=matrice_global[i][2];
    }


  }
  printf("\n%f\n",borneInf);

}


int main(){
    int data[] = {1,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0};
    int taille_data = 23;
    int codeur=0;
    int i;
    int taille_tableau=0;
    char phrase[255];
    int tab_arithmetique[255];
    printf("hdbn = 1 arithmetique =2 \n");
    scanf("%d",&codeur);
    switch (codeur) {
      case 1:
      Codeur_HDBn(data, taille_data, 2);

      break;
      case 2:
      printf("Saisir le mot à encoder \n");
      scanf(" %[^\n]",phrase);
      printf("phrase = %s \n",phrase);

      for(i=0;i<10;i++){
        tab_arithmetique[i]=phrase[i];// on transforme la chaine de caractere en int
        taille_tableau+=1;
        }
        for(i=0;i<8;i++){
        printf("%d|",tab_arithmetique[i]);
        }
      Codeur_arithmetique( tab_arithmetique, taille_tableau);
      break;
    }




}
