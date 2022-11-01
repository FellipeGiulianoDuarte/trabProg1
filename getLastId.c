#include "libTrabalho.h"
/*
 * encontrar ultima imagem cadastrada, pegar id dela, retorna id
 */
int getLastId(char arqFisicoImagensBase[]){
   FILE *pegarId = fopen(arqFisicoImagensBase,"rb");
   if (pegarId == NULL){
      return -1;
   }
   int lastId = 0;
   Imagem imgTemp;
   while (fread(&imgTemp, sizeof(Imagem), 1, pegarId) != 0){
      lastId = imgTemp.id;
   }
   fclose(pegarId);
   return lastId;
}
