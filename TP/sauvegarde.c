void gen_Matrice(int nb_Users){
    int taille_matrice;
    taille_matrice = nb_Users > 8 ? 16:8;
    int matrice[taille_matrice][taille_matrice];
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
        printf("TAILLE TEMP = %d \n\n", taille_temp);
    }

    if (taille_matrice == 8){
        affichage_Matrice_8(8, matrice);
    }
    else{
        affichage_Matrice_16(16, matrice);
    }
    
}

void affichage_Matrice_8(int taille_matrice, int matrice[8][8]){
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

void affichage_Matrice_16(int taille_matrice, int matrice[16][16]){
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