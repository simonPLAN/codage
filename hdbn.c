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

int main(){
    int data[] = {1,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0};
    int taille_data = 23;
    Codeur_HDBn(data, taille_data, 2);
}