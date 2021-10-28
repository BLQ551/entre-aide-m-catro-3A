#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <libmatrices/matrices.h>
#include <ncurses.h>
using namespace std;
using namespace libmatrices;
#define WIDTH 15
#define HEIGHT 10
//***********************************************************
// MAIN
//***********************************************************
int main(int argc, char **argv) {
// créer matrice A et remplir avec nombres aléatoires
// entre 0 et 255
matrice A = creer_matrice(HEIGHT,WIDTH);
srand(time(NULL));
for(int i=0; i<A.hauteur ;i++)
for(int j=0; j<A.largeur; j++)
//Générer des nombres aléatoires entre 0 et 255
A.data[i][j] =rand()%255;
afficher_matrice(&A);//affichage de la matrice
matrice B = seuillage1mat(&A, (int) 128);//seuillage de la matrice
afficher_matrice(&B);//affichage de la matrice
// initialize ncurses window
initscr();
noecho();
cbreak();
curs_set(FALSE);
nodelay(stdscr, TRUE);
//affichage de la matrice binaire dans le window
for (int n=0; n<HEIGHT; n++)
  for (int m=0; m<WIDTH; m++)
  {
  if (B.data[n][m]) mvaddch(n,m,111);//111 pour le o OU mvprintw(n,m,"o");
  else mvaddch(n,m,32);// OU mvprintw(n,m," ");
  }
mvprintw(HEIGHT+1, 0, "press <enter> to quit");
refresh();//refresh screen
usleep(200000);//dodo pour 200000 micro secondes
  // Block waiting here.
  char keyhit;
  std::cout << "\n... press <enter> to quit.\n";
  std::cin.get( keyhit );
endwin();//destroy window
return(0);
}
