#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HORIZ 0
#define VERT 1

/*
Pour l'exercice vous aurez besoin   de generer des entiers aléatoire : rand() renvoit un entier aléatoire.
il s'utilise : rand() % NOMBREMAX + 1 
Pour un entier aléatoire entre 0 et 1 il faut donc faire rand() %2
voir dans la methode main.
*/

void generer(int solution[9][9], int nb_zeros) {
    int i, j, k;
    int genere[9][9];
    for(i=0; i<9; ++i) {
        for(j=0; j<9; ++j) {
            genere[i][j] = solution[i][j];
        }
    }

    int cases_a_zero[nb_zeros][2];
    for(k=0; k<nb_zeros; ++k) {
        i = rand() % 9;
        j = rand() % 9;

        int deja_choisie = 0;
        for(int l=0; l<k; ++l) {
            if(i==cases_a_zero[l][0] && j==cases_a_zero[l][1]) {
                deja_choisie = 1;
                break;
            }
        }
        if(deja_choisie) {
            k--;
        } else {
            cases_a_zero[k][0] = i;
            cases_a_zero[k][1] = j;
            genere[i][j] = 0;
        }
    }

    for(i=0; i<9; ++i) {
        for(j=0; j<9; ++j) {
            solution[i][j] = genere[i][j];
        }
    }
}


/*Écrire une fonction saisir() qui demande à l’utilisateur de saisir au clavier les indices i et j et la valeur v à placer à l’emplacement (i,j).
La fonction doit vérifier la validité des indices et de la valeur.
Si la case n’est pas occupée, la valeur doit être placée dans la grille. remplissage est alors incrémentée*/

int saisir(int grille[9][9]) {
    int i, j, v;
    do {
        printf("Saisir les indices i et j (de 0 a 8) et la valeur v (de 1 a 9), séparation avec espaces: ");
        scanf("%d %d %d", &i, &j, &v);
    } while (i < 0 || i > 8 || j < 0 || j > 8 || v < 1 || v > 9);

    if (grille[i][j] == 0) {
        grille[i][j] = v;
    }

    int nbElementsNonNuls = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grille[i][j] != 0) {
                nbElementsNonNuls++;
            }
        }
    }
    return nbElementsNonNuls;
}

/*
Écrire la fonction verifierLigneColonne() qui prend en paramètre un numéro et un sens (HORIZ ou VERT)
qui vérifie que la ligne ou la colonne (suivant les cas) numéro est bien remplie.
On pourra utiliser un tableau intermédiaire pour vérifier cela. La fonction retournera 1 si tout s’est bien passé, 0 sinon.
 Les constantes HORIZ de valeur 0 et VERT de valeur 1 sont à définir.
*/

int verifierLigneColonne(int grille[9][9], int num, int sens) {
    int elements[9] = {0};
    for (int i = 0; i < 9; i++) {
        if (sens == HORIZ && grille[num][i] != 0) {
            elements[grille[num][i] - 1]++;
        } else if (sens == VERT && grille[i][num] != 0) {
            elements[grille[i][num] - 1]++;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (elements[i] > 1) { // on regarde si la collone est valide ou pas
            return 0;
        }
    }
    return 1;
}




int main(){

    // Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


    int i, j, k;
    int solution[9][9];
    printf("SOLUTION");  
    printf("\n");  
    printf("---------------------------------");  
    printf("\n");  
    for(j=0;j<9; ++j) 
    {
    for(i=0; i<9; ++i)
        solution[j][i] = (i + j*3 +j /3) %9 +1 ; 
    }
    
    for(i=0;i<9; ++i) 
    {
    for(j=0; j<9; ++j)
        printf("%d ", solution[i][j]);
    printf("\n");  
    }
    printf("---------------------------------");  
    printf("\n");

    //toucher le code entre les commentaires


    generer(solution, 30);
    for(i=0;i<9; ++i)
    {
        for(j=0; j<9; ++j)
            printf("%d ", solution[i][j]);
        printf("\n");
    }


    system("pause");
    return 0;
}

