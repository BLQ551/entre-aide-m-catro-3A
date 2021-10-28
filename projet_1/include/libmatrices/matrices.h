
namespace libmatrices
{

// types definition
//**********************************************************

typedef struct matrice
{
int hauteur;
int largeur;
int ** data;
}
matrice;


// functions prototypes
//***********************************************************
//
//creation d'une matrice = allocation de son espace mémoire
matrice creer_matrice(int,int);
//affiche d'une matrice
void afficher_matrice(matrice*);
//addition de deux matrices
matrice add2mat(matrice*,matrice*);
//multiplication terme à terme de deux matrices
matrice multtt2mat(matrice*,matrice*);
//multiplication matricielle de deux matrices
matrice mult2mat(matrice*,matrice*);
//transposition d'une matrice
matrice transpose1mat(matrice*);
//seuillage d'une matrice (binarisation)
matrice seuillage1mat(matrice*,int);

//TODO:
//comptage du nombre d'éléments non nul d'une matrice
//complément terme à terme d'une matrice binaire
//calcul de la moyenne d'une matrice
//calcul du barycentre d'une matrice binaire
//comptage des éléments d'une matrice (histogramme)
//somme des éléments au carré d'une matrice
//inversion d'une matrice
}
