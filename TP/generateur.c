#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>


int * codeur_a_longeur_maximale(int n,int a,int b, int sequence[]){// 5,2
  int longueur_max=pow(2,n)-1;
  int i,j;
  int k,l;
  a--;
  b--;
  printf("a = %d b = %d \n", a, b);
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

/*    for(i=0;i<longueur_max;i++){
      for(j=0;j<n;j++){
        printf("%d ",matrice[i][j]);
      }
      printf("\n");
    }
    */
    printf("\n");

    for(i=0;i<longueur_max;i++){
printf("%d|",sequence[i] );
}
printf("\n");



  }//fin fonction


int * codeur_gold(int resultat1[],int resultat2[],int resultat3[],int longueur1,int longueur2){
  int i,j;
  int longueur_max1=pow(2,longueur1)-1;
  int longueur_max2=pow(2,longueur2)-1;
  int max,min;

  if(longueur_max1<longueur_max2){
    max=longueur_max2;
    min=longueur_max1;
  }else{
    max=longueur_max1;
    min=longueur_max2;

  }

//  printf("\n%d\n",resultat1[0]);


  for(i=0;i<max;i++){
    if(i<min){
      resultat3[i]=resultat1[i]^resultat2[i];

    }else{
    if(max==longueur_max1){
      resultat3[i]=resultat2[i]^0;
    }else{
      resultat3[i]=resultat1[i]^0;
    }
    }
  }
  printf("\n" );

  for(i=0;i<max;i++){
    printf("%d|",resultat3[i] );
  }
  printf("\n" );
}

int main(){

  int longueur1=5;
  int a1=5;
  int b1=2;
  int longueur2=5;
  int a2=3;
  int b2=1;
  int longueur3=7;
  int a3=3;
  int b3=1;
  int longueur4=2;



  int resultat1[255];
  int resultat2[255];
  int resultat3[255];
  int resultat4[255];
  int resultat5[255];

printf("\nresultat1 = ");
codeur_a_longeur_maximale(longueur1,a1,b1,resultat1);

printf("\nresultat2 = ");
codeur_a_longeur_maximale(longueur2,a2,b2,resultat2);


printf("\nresultat3 = ");
codeur_a_longeur_maximale(longueur3,a3,b3,resultat4);

printf("\ngold1 = ");
codeur_gold(resultat1,resultat2,resultat3,longueur1,longueur2);

printf("\ngold2 = ");
codeur_gold(resultat3,resultat4,resultat5,longueur3,longueur4);

}
