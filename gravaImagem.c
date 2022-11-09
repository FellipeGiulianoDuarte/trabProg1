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
   fprintf(arqSaida, "%s\n%d %d\n%d\n", tipo, col, lin, maxval);
   /*
   for (int i = 0; i < lin; i++){
      for (int j = 0; j < col; j++){
         fprintf(arqSaida, "%d", mat[i][j]); 
      }
      fprintf(arqSaida, "\n");
   } */
   fclose(arqSaida);
   return 0;
}
