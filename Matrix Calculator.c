#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "ahmedbibo.h"

/********************************************************************************************/
void startPro1() {
    int choix;
    
    printf("									Voulez-vous continuez ? (Appuyez sur 0 pour oui ou sur 7 pour quitter) : ");
    choix=scan2();
    
    if (choix == 0) {
        // Code pour commencer
        // Ajoutez ici le code que vous souhaitez exécuter lorsque l'utilisateur choisit de commencer.
    } else if (choix == 7) {
        // Code pour quitter
		system("cls"); 
       end();
       	printf("\n");
	printf("\n");
	calma();
        exit(0);
// Quitte la fonction et termine le programme
    } else {
        // Choix invalide
        // Ajoutez ici le code pour gérer le cas où l'utilisateur entre un choix invalide.
        startPro1();
    }
    
    // Ajoutez ici le reste du code que vous souhaitez exécuter après le choix de l'utilisateur.
}
/****************************************************************************************/
void startProgram() {
    int choix;
    
    printf("									Voulez-vous commencer ? (Appuyez sur 0 pour oui ou sur 7 pour quitter) : ");
    choix=scan2();
    
    if (choix == 0) {
        // Code pour commencer
        // Ajoutez ici le code que vous souhaitez exécuter lorsque l'utilisateur choisit de commencer.
    } else if (choix == 7) {
        // Code pour quitter
		system("cls"); 
       end();
       	printf("\n");
	printf("\n");
	calma();
        exit(0);
// Quitte la fonction et termine le programme
    } else {
        // Choix invalide
        // Ajoutez ici le code pour gérer le cas où l'utilisateur entre un choix invalide.
        startProgram();
    }
    
    // Ajoutez ici le reste du code que vous souhaitez exécuter après le choix de l'utilisateur.
}

int scan() {
   int nombre;
   while(scanf("%d", &nombre) != 1) {
      printf("Erreur : veuillez entrer un nombre entier valide.\n");
      while(getchar() != '\n'); // Vider le tampon d'entrée
      printf("\n");
      printf("Entrez un nombre entier : ");
   }
return(nombre);
}

int scan2() {
   int nombre;
   while(scanf("%d", &nombre) != 1) {

      while(getchar() != '\n'); // Vider le tampon d'entrée
     
      printf("									Voulez-vous commencer ? (Appuyez sur 0 pour oui ou sur 7 pour quitter) : ");
   }
return(nombre);
}

void transpose(float A[][100], float AT[][100], int n) {
    // Cette fonction calcule la transpose de la matrice A et la stocke dans AT.
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            AT[i][j] = A[j][i];
        }
    }
}

float determinant(float A[][100], int n) {
    // Cette fonction calcule le déterminant de la matrice A en utilisant la méthode de Laplace.
    float det = 0;
    float submatrix[100][100];
    int i, j, k;
    if (n == 1) {
        return A[0][0];
    }
    else if (n == 2) {
        return (A[0][0]*A[1][1] - A[0][1]*A[1][0]);
    }
    else {
        for (i = 0; i < n; i++) {
            int subi = 0;
            for (j = 1; j < n; j++) {
                int subj = 0;
                for (k = 0; k < n; k++) {
                    if (k == i) {
                        continue;
                    }
                    submatrix[subi][subj] = A[j][k];
                    subj++;
                }
                subi++;
            }
            det = det + (A[0][i] * pow(-1, i) * determinant(submatrix, n-1));
        }
    }
    return det;
}

void cofactor(float A[][100], float AC[][100], int n) {
    // Cette fonction calcule la matrice des cofacteurs de la matrice A et la stocke dans AC.
    int i, j, k, l;
    float submatrix[100][100];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int subi = 0, subj = 0;
            for (k = 0; k < n; k++) {
                for (l = 0; l < n; l++) {
                    if (k != i && l != j) {
                        submatrix[subi][subj] = A[k][l];
                        subj++;
                        if (subj == n-1) {
                            subi++;
                            subj = 0;
                        }
                    }
                }
            }
            AC[i][j] = pow(-1, i+j) * determinant(submatrix, n-1);
        }
    }
}

int inverse(float A[][100], float A_inv[][100], int n) {
    // Cette fonction calcule la matrice inverse de la matrice A et la stocke dans A_inv.
    float det = determinant(A, n);
    if (det == 0) {
        return 0;
    }
    float AC[100][100];
    cofactor(A, AC, n);
    float AT[100][100];
    transpose(AC, AT, n);
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            A_inv[i][j] = AT[i][j] / det;
        }
    }
    return 1;
}

// Fonction qui détermine si une matrice est creuse
int estCreuse(float A[][100], int n) {
    int nbZeros = 0;
    int i,j;

    // Parcours de la matrice pour compter le nombre de zéros
    for (i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            if (A[i][j] == 0) {
                nbZeros++;
            }
        }
    }

    // Calcul du pourcentage de zéros dans la matrice
    float pourcentage = (float) nbZeros / (n * n) * 100;

    // Si le pourcentage est supérieur à 50%, la matrice est creuse
    if (pourcentage > 50) {
        return 1;
    } else {
        return 0;
    }
}

int estSymetrique(float A[100][100],int n) {
int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j] != A[j][i])	
                return 0;
            }
        }
    return 1;
}

void lower_triangular_matrix(int n, float A[][100]) {
	int i,j;
	float upper_triangular[100][100];
	  for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            upper_triangular[i][j] = A[i][j];
        }
    }
    // Recherche de la matrice triangulaire inférieure
    for (i = 0 ; i < n ; i++) {
        for (j = 0 ; j < i ; j++) {
            upper_triangular[i][j] = 0 ;
        }
    }
    // Affichage de la matrice triangulaire inférieure
    printf("La matrice triangulaire superieure est :\n") ;
    for (i = 0 ; i < n ; i++) {
        for (j = 0 ; j < n ; j++) {
            printf("%.0f\t ", upper_triangular[i][j]) ;
        }
        printf("\n") ;
    }
}

void matrice_tri_sup(float A[][100], int n) {
	int i,j;
		float upper_triangular[100][100];
	  for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            upper_triangular[i][j] = A[i][j];
        }
    }
  // Trouver la matrice triangulaire supérieure
  for (i = 0; i < n; i++) {
    for (j = 0; j < i; j++) {
      upper_triangular[j][i] = 0;
    }
  }

    // Afficher la matrice triangulaire supérieure
  printf("La matrice triangulaire inferieure est :\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%.0f\t ", upper_triangular[i][j]);
    }
    printf("\n");
  }
}

int main() {
    int n, i, j, choix = 0;
    float A[100][100], A_inv[100][100], pourcentage;
    int nbZeros;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
    boumir();
    printf("\n");
    printf("\n");
    printf("\n");
    SetConsoleTextAttribute(hConsole, 13);
    descrption();
    printf("\n");
    SetConsoleTextAttribute(hConsole, 6);
    printf("\n");
	startProgram();
	system("cls");
	matrixe();
	printf("\n");
    printf("\n");
    printf("\n");
    SetConsoleTextAttribute(hConsole, 13);
    printf("Saisie de votre matrice : \n");
    SetConsoleTextAttribute(hConsole, 6);
    printf("\n");
    printf("Entrez la taille de la matrice (n x n) : ");
    n=scan();
    SetConsoleTextAttribute(hConsole, 6); 
    printf("\nEntrez les elements de la matrice : \n\n");
    for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
    printf("\t\tA[%d][%d] = ", i, j);
    scanf("%f", &A[i][j]);
    }
    }
    printf("\n");
    system("cls");
    
    while (choix != 7) {
    SetConsoleTextAttribute(hConsole, 6);
    		monu();
    		printf("\n");
    		printf("\n");
    		printf("\n");
    SetConsoleTextAttribute(hConsole, 13);
    	    menu();
    		printf("\n");

    			SetConsoleTextAttribute(hConsole, 6);
    		           	    printf("\nVoici la matrice : \n"); 
				for (i=0;i<n;i++)
				{
				for (j=0;j<n;j++)
				printf("%.0f\t",A[i][j]);
				printf("\n");
				}

    		printf("\n");
    		SetConsoleTextAttribute(hConsole, 6);
        printf("Entrer votre choix (entrer '7' pour quitter) : ");
        choix = scan();
        printf("\n");
        system("cls");	
        switch (choix) {
            case 1: {
            		SetConsoleTextAttribute(hConsole, 6);
            	inversee();
            	printf("\n");
           	    printf("\nVoici la matrice : \n"); 
				for (i=0;i<n;i++)
				{
				for (j=0;j<n;j++)
				printf("%.0f\t",A[i][j]);
				printf("\n");
				}
            	printf("\n");
                float det = determinant(A, n);
                if (det == 0) {
                    printf("La matrice n'est pas inversible.\n\n");
                } else {
                    if (inverse(A, A_inv, n)) {
                        printf("La matrice inverse est : \n\n");
                        for (i = 0; i < n; i++) {
                            for (j = 0; j < n; j++) {
                                printf("%.2f\t ", A_inv[i][j]);
                            }
                            printf("\n");
                        }
                        printf("\nLe determinant est : %.2f\n\n", det);
                    }
                }
                   startPro1();
                system("cls");
                break;
                system("cls");
            }
            case 2: {
            		SetConsoleTextAttribute(hConsole, 6);
            	creusee();
            	printf("\n");
           	    printf("\nVoici la matrice : \n"); 
				for (i=0;i<n;i++)
				{
				for (j=0;j<n;j++)
				printf("%.0f\t",A[i][j]);
				printf("\n");
				}
				printf("\n");
                if (estCreuse(A, n)) {
                    printf("La matrice est creuse.\n\n");
                } else {
                    printf("La matrice n'est pas creuse.\n\n");
                }
                     startPro1();
                system("cls");
                break;
                system("cls");
            }
            case 3: {
            		SetConsoleTextAttribute(hConsole, 6);
            	symetric();
            	printf("\n");
            	    printf("\nVoici la matrice : \n"); 
				for (i=0;i<n;i++)
				{
				for (j=0;j<n;j++)
				printf("%.0f\t",A[i][j]);
				printf("\n");
				}
				printf("\n");
    if (estSymetrique(A,n)) {
        printf("La matrice est symetrique.\n");
    } else {
        printf("La matrice n'est pas symetrique.\n");
    }
         startPro1();
                system("cls");
     break;
     system("cls");
}
case 4:{
		SetConsoleTextAttribute(hConsole, 6);
	inff();
	printf("\n");
    printf("La matrice d'origine est :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.0f\t", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
      lower_triangular_matrix(n, A);
           startPro1();
                system("cls");
     break;
     system("cls");
}

case 5:{
		SetConsoleTextAttribute(hConsole, 6);
	supp();
	printf("\n");
    printf("La matrice d'origine est :\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.0f\t", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
     matrice_tri_sup(A, n);
          startPro1();
                system("cls");
	break;
	system("cls");
}

case 6:{
	    SetConsoleTextAttribute(hConsole, 6);
	    new();
    printf("\n");
    printf("Entrez la taille de la matrice (n x n) : ");
    n=scan();
    SetConsoleTextAttribute(hConsole, 6); 
    printf("\nEntrez les elements de la matrice : \n\n");
    for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
    printf("\t\tA[%d][%d] = ", i, j);
    scanf("%f", &A[i][j]);
    }
    }
    printf("\nVoici la matrice : \n"); 
	for (i=0;i<n;i++)
	{
	for (j=0;j<n;j++)
	printf("%.0f\t",A[i][j]);
	printf("\n");
	}
	printf("\n");
    startPro1();
    system("cls");
	break;
}
    case 7:{
    end();
	printf("\n");
	printf("\n");
	calma();
	    exit(0);
		break;
	}
}
}
}

