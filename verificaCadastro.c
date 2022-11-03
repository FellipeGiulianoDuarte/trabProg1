#include "libTrabalho.h"
/*
 * deve-se abrir o arquivo, percorrer ele, verificar se existe nome já cadastrado no banco
 */
int verificaCadastro(char arqFisicoImagensBase[], char nomeImagem[]){
   //abre arquivo
   FILE *verificar = fopen(arqFisicoImagensBase,"a+b");
   if (verificar == NULL){
      return -1;
   }
   //volta para início
   rewind(verificar);
   Imagem imgTemp;
   //percorre arquivo
   while (fread(&imgTemp, sizeof(Imagem), 1, verificar) != 0){
      if(strcmp(imgTemp.nome, nomeImagem) == 1){ //compara strings
         fclose(verificar);
         return 1;
      }
   }
   //fecha arquivo
   fclose(verificar);
   return 0;
}
