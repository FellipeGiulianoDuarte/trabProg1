#include "libTrabalho.h"
/*
 * deve-se abrir o arquivo, percorrer ele, verificar se existe nome já cadastrado no banco
 */
int verificaCadastro(char arqFisicoImagensBase[], char nomeImagem[]){
   FILE *verificar = fopen(arqFisicoImagensBase,"rb");
   if (verificar == NULL){
      return -1;
   }
   Imagem imgTemp;
   while (fread(&imgTemp, sizeof(Imagem), 1, verificar) != 0){
      if(strcmp(imgTemp.nome, nomeImagem) == 1){ //compara strings
         fclose(verificar);
         return 1;
      }
   }
   fclose(verificar);
   return 0;
}
