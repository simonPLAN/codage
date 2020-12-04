#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int saisir_Utilisateurs(){ /* Fonction servant à demander à l'utilisateur de saisir via l'entrée standard le nombre d'utilisateurs */
    int nb_Users;
    do{
    printf("Saisissez le nombre d'utilisateur parmis (1/2/4/8/16) : ");
    scanf("%d",&nb_Users);
    }while(nb_Users < 1 || nb_Users > 16);
    return nb_Users;
}

int inverser(int cible){ /* Fonction permettant d'inverser (-1 / 1) un élement int cible , utile pour inverser les valeurs d'une matrice */
    return cible == -1? 1:-1;
}

int taille_matricielle(int nb_Users){ /* Fonction permettant de connaître la taille d'une matrice en fonction du nombre d'utilisateurs */
    return nb_Users > 8 ? 16:8;
}

void affichage_Matrice_Custom(int hauteur_matrice, int longueur_matrice, int ** matrice){ /* Permet d'afficher une matrice n'étant pas carré */
    int j;
    printf("Affichage de la matrice de taille : %d \n", hauteur_matrice*longueur_matrice);
    for( j = 0; j < longueur_matrice; j++ ){
        printf("%d ",matrice[hauteur_matrice][j]);
    }
    printf("\n");
}

void affichage_Matrice(int taille_matrice, int ** matrice){ /* Fonction d'affichage de matrice carré */
    int i, j;
    printf("Affichage de la matrice de taille : %d \n", taille_matrice);
    for( i = 0; i < taille_matrice; i++ ){
        for( j = 0; j < taille_matrice; j++ ){
            printf("%d ",matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void affichage_Code(int nb_Users, int ** code){ /* Permet d'afficher une matrice contenant des codes séquences */
    int i, j;
    for( i = 0; i < nb_Users; i++ ){
        for( j = 0; j < 3; j++ ){
            printf("%d ",code[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void affichage_sequence(int nb_Users, int ** sequence){ /* Fonction d'affichage de la matrice de séquence  */
    int i, j;
    for( i = 0; i < nb_Users; i++ ){
        for( j = 0; j < taille_matricielle(nb_Users) * 3; j++ ){
            if(sequence[i][j]==1){
                printf(" %d ",sequence[i][j]);
            }
            else{
                printf("%d ",sequence[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int ** Matrice_Hadamard(int nb_Users, int ** matrice){ /* Génération de la matrice d'Hadamard en fonction du nombre d'utilisateurs */
    int taille_matrice;
    taille_matrice = nb_Users > 8 ? 16:8;
    int taille_temp;
    int i, j;
    matrice[0][0] = 1;
    for (taille_temp = 2; taille_temp <= taille_matrice ; taille_temp*=2){
        for( int i = 0; i < taille_temp; i++ ){
            for( int j = 0; j < taille_temp; j++ ){
                if (i < taille_temp/2 && j < taille_temp/2){}
                else if (i >= taille_temp/2 && j >= taille_temp/2){
                    matrice[i][j] = inverser(matrice[i - taille_temp/2][j - taille_temp/2]);
                }
                else if (i >= taille_temp / 2){
                    matrice[i][j] = matrice[i-taille_temp/2][j];
                }
                else{
                    matrice[i][j] = matrice[i][j-taille_temp/2];
                }
            }
        }
    }
    affichage_Matrice(taille_matrice, matrice);
    return matrice;
}

int ** copie_matrice(int nb_Users, int ** matrice, int **code,int **sequence){ /* Génère une matrice séquence en fonction des codes */
    int i,j,k,l;
    for(i=0;i<nb_Users;i++){
        for(j=0;j<3;j++){
            /* On applique la règle du "Si le code est égale à 1 on recopie la matrice d'Hadamard sinon on inverse la valeur à recopier */
            if(code[i][j] == 1){
                for(l=0;l<taille_matricielle(nb_Users);l++){
                    sequence[i][l + j * taille_matricielle(nb_Users)] = matrice[i][l];
                }
            }
            else{
                for(l=0;l<taille_matricielle(nb_Users);l++){
                    sequence[i][l + j * taille_matricielle(nb_Users)] = inverser(matrice[i][l]);
                }
            }
        }
    }
}

void affichage_sequence_etalement( int nb_Users, int * sequence){ /* Fonction d'affichage de l'étalement */
    int i;
    for( i = 0; i < taille_matricielle(nb_Users) * 3; i++ ){
        printf("%d ",sequence[i]);
    }
    printf("\n");
}



int * etalement_sequence(int nb_Users, int ** sequence, int * etalement){ /* Réalise l'étalement et rempli un tableau int * etalement en conséquence */
  int i, j;
  int somme = 0;
    for( i = 0; i <  taille_matricielle(nb_Users) * 3; i++ ){ //    ligne
        for( j = 0; j < nb_Users; j++ ){ // colonne
            somme += sequence[j][i];
        }
        etalement[i]=somme;
        somme = 0;
    }
}

int * canalIdeal( int * etalement){
    printf("passage dans le canalIdeal\n");
    return etalement;
}


int ** desetalement_sequence(int nb_Users, int * etalement, int ** matrice, int ** sequence, int ** desetalement){ /* Effectue le désétalement */
    int i, j, x, y;
    int stockage[nb_Users][taille_matricielle(nb_Users)*3];
    int compteur = 0;
    int compteur2 = 0;
    int compteur3 = 0;
    /* On stock d'abord dans une matrice temporaire "stockage" le produit de la matrice d'Hadamard avec l'étalement */
    for (x = 0; x < nb_Users; x++){
        for (j = 0; j < taille_matricielle(nb_Users) * 3; j++){
            stockage[x][j] = matrice[x][(j - (j/taille_matricielle(nb_Users)) * taille_matricielle(nb_Users))] * etalement[j];
        } 
    }
    /* Partie débogage utile pour vérifier que la multiplication s'est bien effectuée */
    /*
    for (i = 0; i < nb_Users; i++){
        for (j = 0; j < taille_matricielle(nb_Users) * 3 ; j++){
            printf(" %d ", stockage[i][j]);
        }
        printf("\n");
    }
    */

    /* On parcourt la matrice temporaire "stockage" afin de retrouver notre code initiale */
    for (x = 0; x < 3; x++){
        for (i = 0; i < nb_Users; i++){
            for (j = 0; j < 3 * taille_matricielle(nb_Users); j++){
                if (j < taille_matricielle(nb_Users)){
                    compteur += stockage[i][j];
                }
                else if (j >= taille_matricielle(nb_Users) && j < taille_matricielle(nb_Users)*2){
                    compteur2 += stockage[i][j];
                }
                else{
                    compteur3 += stockage[i][j];
                }
            }
            if (compteur <= 0){
                desetalement[i][0] = 0;
            }
            else{
               desetalement[i][0] = 1; 
            }
            if (compteur2 <= 0){
                desetalement[i][1] = 0;
            }
            else{
               desetalement[i][1] = 1; 
            }
            if (compteur3 <= 0){
                desetalement[i][2] = 0;
            }
            else{
               desetalement[i][2] = 1; 
            }
            compteur = 0;   
            compteur2 = 0;   
            compteur3 = 0;   
        }
    }
}

int main (){
    srand(time(NULL));
    int nb_Users = saisir_Utilisateurs();
    int ** matrice = NULL;
    int ** code = NULL;
    int ** sequence = NULL;
    int * etalement = NULL;
    int ** desetalement = NULL;
    int i,j;
    /* Allocation mémoire de la matrice */
    matrice = malloc(sizeof(*matrice) * taille_matricielle(nb_Users));
    for (int i = 0; i < taille_matricielle(nb_Users); i++){
        matrice[i] = malloc(sizeof(**matrice) * taille_matricielle(nb_Users));
    }
    /* Génération de la matrice d'Hadamard */
    Matrice_Hadamard(nb_Users, matrice);
    /* Fin Hadamard */

    /* Allocation mémoire des codes de séquence */
    code = malloc(sizeof(*code) * nb_Users);
    for ( i = 0; i < nb_Users; i++){
        code[i] = malloc(sizeof(**code) * 3);
    }
    /* On génère aléatoirement des codes de séquence */
    for( i = 0; i < nb_Users; i++ ){
        for( j = 0; j < 3; j++ ){
            code[i][j] = rand() % 2; //generation de nombre aleatoire entre  et 1
        }
    }
    affichage_Code(nb_Users, code);
    /* Fin code */

    /* Allocation mémoire des séquences */ 
    sequence = malloc(sizeof(*sequence) * nb_Users);
    for ( i = 0; i < nb_Users; i++){
        sequence[i] = malloc(sizeof(**sequence) * taille_matricielle(nb_Users) * 3 );
    }

    copie_matrice(nb_Users, matrice, code, sequence);
    affichage_sequence(nb_Users, sequence);
    /* Fin sequence */

    /* Début étalement*/
    etalement = malloc(sizeof(*etalement) * taille_matricielle(nb_Users) * 3 );
    etalement_sequence( nb_Users, sequence,etalement);
    affichage_sequence_etalement(nb_Users,etalement);
    /* Fin étalement */
    /* Début canalIdeal */
    canalIdeal( etalement);
    /* Fin canalIdeal */

    /* Allocation mémoire des codes de séquence */
    desetalement = malloc(sizeof(*desetalement) * nb_Users);
    for ( i = 0; i < nb_Users; i++){
        desetalement[i] = malloc(sizeof(**desetalement) * 3);
    }
    /* Début désétalement */
    desetalement_sequence(nb_Users,etalement,matrice, sequence, desetalement);
    printf("\n \n DESETALEMENT \n \n");
    affichage_Code(nb_Users, desetalement);
    /* Fin désétalement */

    return 0;

}