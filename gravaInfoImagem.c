#include "libTrabalho.h"
/*
 * abre arquivo e faz um append com dados da imagem recebida
 */
/****** Completar *****/
int gravaInfoImagem(char arqFisicoImagensBase[], Imagem img){
   FILE *gravarImagem = fopen(arqFisicoImagensBase, "ab");
	if (gravarImagem == NULL){
      return -1;
   }
   fwrite(&img, sizeof(Imagem), 1, gravarImagem);
	fclose(gravarImagem);
   return 1;
}
