// Chasse_Tresor.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <stdio.h>
const int GRID_SIZE = 5;
const char PLAYER = '@';
const char TREASURE = 'T';
const char OBSTACLE = '#';
const char EMPTY = '.';
const int FAUX = 0;
const int VRAI = 1;

// Déclaration des fonctions
void initGrid(int grid[GRID_SIZE][GRID_SIZE], int* playerX, int* playerY);
void displayGrid(int grid[GRID_SIZE][GRID_SIZE]);
int movePlayer(int grid[GRID_SIZE][GRID_SIZE], int* playerX, int* playerY, int direction);

int main()
{
    int iMap[GRID_SIZE][GRID_SIZE];
    int playerX = 0;
    int playerY = 0;
    initGrid(iMap, &playerX, &playerY);
    int verif = FAUX;

    int iSaisi = 0;
    do 
    {
        displayGrid(iMap);
        printf("Deplacements (1:haut, 2:bas, 3:gauche, 4:droite) : ");
        scanf_s("%d", &iSaisi);
        if (iSaisi > 4 || iSaisi <= 0)
        {
            printf("Ce deplacement est impossible!\n");
        }
        else 
        {
            if (movePlayer(iMap, &playerX, &playerY, iSaisi) == VRAI) 
            {
                printf("Vous avez trouve le tresor!");
                verif = VRAI;
            }
        }

    } while (verif == FAUX);
}

//Définition des fonctions avec commentaires d'en-tête
void initGrid(int grid[GRID_SIZE][GRID_SIZE], int* playerX, int* playerY) 
{
    for (int i = 0; i <= GRID_SIZE - 1; i++) 
    {
        for (int j = 0; j <= GRID_SIZE - 1; j++) 
        {
            grid[i][j] = EMPTY;
        }
    }

    grid[0][0] = PLAYER;
    //*playerX = 0;
    //*playerY = 0;

    grid[4][4] = TREASURE;

    grid[1][1] = OBSTACLE;
    grid[2][3] = OBSTACLE;
    grid[3][2] = OBSTACLE;
}

void displayGrid(int grid[GRID_SIZE][GRID_SIZE])
{
    // Déclaration de compteurs
    int iLignes, iColonnes = 0;

    // Pour toutes les lignes de la matrice
    for (iLignes = 0; iLignes < GRID_SIZE; iLignes++) 
    {
        // Pour toutes les colonnes de la matrice
        for (iColonnes = 0; iColonnes < GRID_SIZE; iColonnes++) {
            // Affichage de l'élément de la matrice à la colonne iColonnes
            // et à la ligne iLignes
            printf("%c\t", grid[iLignes][iColonnes]);
        }
        printf("\n");
    }
}

int movePlayer(int grid[GRID_SIZE][GRID_SIZE], int* playerX, int* playerY, int direction) 
{
    int newXPosition = *playerX;
    int newYPosition = *playerY;

    if ((direction == 1) && (*playerX > 0)) // Haut
    {
        newXPosition = newXPosition - 1;
    }
    else if ((direction == 2) && (*playerX < GRID_SIZE - 1)) // Bas
    {
        newXPosition = newXPosition + 1;
    }
    else if ((direction == 3) && (*playerY > 0)) // Gauche
    {
        newYPosition = newYPosition - 1;
    }
    else if ((direction == 4) && (*playerY < GRID_SIZE - 1)) // Droite
    {
        newYPosition = newYPosition + 1;
    }

    if (grid[newXPosition][newYPosition] == OBSTACLE) 
    {
        printf("Il y a un obstacle!\n");
        return FAUX;
    }

    grid[*playerX][*playerY] = EMPTY;

    *playerX = newXPosition;
    *playerY = newYPosition;

    if (grid[*playerX][*playerY] == TREASURE) 
    {
        return VRAI;
    }

    grid[*playerX][*playerY] = PLAYER;

    return FAUX;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
