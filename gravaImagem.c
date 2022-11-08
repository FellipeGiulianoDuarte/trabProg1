#include "libTrabalho.h"
/*
 * salvar em um novo arquivo ArqSaida a imagem em **mat
 */
int gravaImagem (char *nomeArqSaida, char *tipo, int lin, int col, int maxval, int **mat){
   FILE *arqSaida = fopen(nomeArqSaida, "w");
   if(arqSaida = NULL){
      printf("\nErro ao criar arquivo - gravaImagem.\n");
      return 1;
   }
   fprintf(arqSaida, "%s\n", tipo);
   fprintf(arqSaida, "%d ", col);
   fprintf(arqSaida, "%d\n", lin);
   fprintf(arqSaida, "%d\n", maxval);
   for (int i = 0; i < lin; i++){
      for (int j = 0; j < col; j++){
         fprintf(arqSaida, "%d", mat[i][j]); 
      }
      fprintf(arqSaida, "\n");
   } 

   return 0;
}
