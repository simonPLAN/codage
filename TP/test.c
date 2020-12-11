#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>


int * codeur_a_longeur_maximale(int n,int a,int b, int resultat[]){
  int longueur_max=pow(2,n)-1;
  int i,j;
  int k,l;
  a--;
  b--;
  int sequence[longueur_max];
  int matrice[longueur_max][n];
  // on met la matrice a 0
  for(i=0;i<longueur_max;i++){
    for(j=0;j<n;j++){
      matrice[i][j]=0;
      }
    }
  for(i=0;i<n;i++){
      matrice[0][i]=1;
  }
  //printf("a = %d b= %d\n ",a,b);

  for(i=0;i<longueur_max;i++){
    k=matrice[i][a];
    l=matrice[i][b];
    //printf("k = %d l= %d\n ",k,l);
    matrice[i+1][0]=k^l;
    for(j=0;j<n-1;j++){
      matrice[i+1][j+1]=matrice[i][j];
    }
  }

for(i=0;i<longueur_max;i++){
  sequence[i]=matrice[i][n-1];
}


    for(i=0;i<longueur_max;i++){
      for(j=0;j<n;j++){
        printf("%d ",matrice[i][j]);
      }
      printf("\n");
    }
    printf("\n");

    for(i=0;i<longueur_max;i++){
printf("%d|",sequence[i] );
}
printf("\n");



}//fin fonction


int * codeur_gold(int resultat1[],int resultat2[],int resultat3[], int n){
  int i,j;
  int longueur_max=pow(2,n)-1;
  printf("\n%d\n",resultat1[0]);
  for(i=0;i<longueur_max;i++){
  //  resultat3[i]=resultat1[i]^resultat2
  }
  for(i=0;i<longueur_max;i++){
printf("%d|",resultat3[i] );
}
}

int main(){
  int longueur=5;
  int a=5;
  int b=2;
  int resultat1[255];
  int resultat2[255];
  int resultat3[255];

codeur_a_longeur_maximale(longueur,a,b,resultat1);

 //a=3;
 //b=1;
//codeur_a_longeur_maximale(longueur,a,b,resultat2);

//codeur_gold(resultat1,resultat2,resultat3,longueur);
}