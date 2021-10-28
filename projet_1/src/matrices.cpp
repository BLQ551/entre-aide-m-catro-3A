#include <cstdlib>
#include <iostream>
#include <libmatrices/matrices.h>

using namespace std;

namespace libmatrices
{



// functions definitions
//***********************************************************

//CREATION D'UNE MATRICE
matrice creer_matrice(int hauteur, int largeur){
       matrice m;
       m.hauteur = hauteur;
       m.largeur = largeur;
       m.data = (int**)malloc(m.hauteur*sizeof(int *));
       for(int i = 0; i< m.hauteur; ++i){
          // initialiser les cases à 0 avec calloc
          m.data[i] = (int *)calloc(m.largeur,sizeof(int));
       }
       return m;
}

//AFFICHAGE D'UNE MATRICE
void afficher_matrice(matrice* M){
     for(int i = 0; i < (*M).hauteur; i++) {
        for(int j = 0; j < (*M).largeur; j++) {
            cout << (*M).data[i][j] ;
            cout << "\t";
        }
        //retour à la ligne
        cout << "\n";
     }
     cout << "\n";
}

//ADDITIONNER 2 MATRICES
matrice add2mat(matrice* prem, matrice* deuz)
{
int n,m;
matrice result;
result = creer_matrice((*prem).hauteur, (*prem).largeur);

for (n=0; n<(*prem).hauteur; n++)
  for (m=0; m<(*prem).largeur; m++)
  {
    result.data[n][m]=(*prem).data[n][m]+(*deuz).data[n][m];
    //printf("element i:%i, j:%i, =%i",n,m,(*result).tab[n][m]);
    //printf("\n");
  }
return result;
}

//TRANSPOSER UNE MATRICE
matrice transpose1mat(matrice* prem)
{
int n,m;
matrice result;

result = creer_matrice((*prem).largeur, (*prem).hauteur);

for (n=0; n<result.hauteur; n++)
  for (m=0; m<result.largeur; m++)
  {
    result.data[n][m]=(*prem).data[m][n];
    //printf("element i:%i, j:%i, =%i",n,m,(*result).tab[n][m]);
    //printf("\n");
  }
return result;
}

//MULTIPLIER DEUX MATRICES
matrice mult2mat(matrice* prem, matrice* deuz)
{
      matrice result = creer_matrice((*prem).hauteur, (*deuz).largeur);
      if ((*prem).largeur != (*deuz).hauteur)
          {
          cout << "MATRICE DIMENSIONS MISMATCH" << endl;
          }
      else
      {
      for(int I = 0; I < result.hauteur; I++)
      for(int J = 0; J < result.largeur; J++)
      {
          result.data[I][J] = 0;
          for(int K = 0; K < (*prem).largeur; K++)
          {
              result.data[I][J] += (*prem).data[I][K] * (*deuz).data[K][J];
          //cout << result.data[I][J];
          }
      }
      }
      return result;
}

//MULTIPLIER DEUX MATRICES TERMES À TERMES
matrice multtt2mat(matrice* prem,matrice* deuz)
{
      matrice result = creer_matrice((*prem).hauteur, (*deuz).largeur);
      if  (((*prem).largeur != (*deuz).largeur) || ((*prem).hauteur != (*deuz).hauteur))
          {
          cout << "MATRICE DIMENSIONS MISMATCH" << endl;
          }
      else
      {
      for(int I = 0; I < result.hauteur; I++)
      for(int J = 0; J < result.largeur; J++)
      {
          result.data[I][J] += (*prem).data[I][J] * (*deuz).data[I][J];
          //cout << result.data[I][J];
          }
      }
       return result;

}


//SEUILLAGE D'UNE MATRICE AU SEUIL seuil
matrice seuillage1mat(matrice* M, int seuil)
{
matrice result;
result = creer_matrice((*M).hauteur, (*M).largeur);
// binariser la matrice, seuil = 128
for(int i=0; i<result.hauteur ;i++)
for(int j=0; j<result.largeur; j++)
if ((*M).data[i][j] < seuil) result.data[i][j] =0;
else result.data[i][j] = 1;
return result;
}
//complement d’une matrice binaire


}
