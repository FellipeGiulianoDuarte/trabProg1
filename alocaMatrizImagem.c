#include "libTrabalho.h"
/*
 * semelhante a alocaString, mas aloca em relacao a numero de int lin e int col
 * lembrar de desalocar
 */
int **alocaMatrizImagem (int lin, int col){
   int i; 
   int **mat;
   //alocacao das linhas
   mat = malloc (lin * sizeof (int*)) ;
   // aloca cada uma das linhas (vetores de col inteiros)
   for (i=0; i < lin; i++){
      mat[i] = malloc (col * sizeof (int));
   }   
   if (mat == NULL){
      printf("\nMemória insuficiente - função alocaMatrizImagem\n");
   }
   return mat;
}
