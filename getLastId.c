#include "libTrabalho.h"
/*
 * encontrar ultima imagem cadastrada, pegar id dela, retorna id
 */
int getLastId(char arqFisicoImagensBase[]){
   //abre arquivo
   FILE *pegarId = fopen(arqFisicoImagensBase,"rb");
   if (pegarId == NULL){
      return -1;
   }
   int lastId = 0;
   Imagem imgTemp;
   //percorre arquivo
   while (fread(&imgTemp, sizeof(Imagem), 1, pegarId) != 0){
      lastId = imgTemp.id;
   }
   //fecha arquivo
   fclose(pegarId);
   return lastId;
}
