#include "libTrabalho.h"
/*
 * encontra imagem por ID, altera nome do proprietario e data de modificacao
 */
int alteraImagem(char arqFisicoImagensBase[], int id){
   //abre arquivo
   FILE *pegarImagem = fopen(arqFisicoImagensBase,"r+b");
   if (pegarImagem == NULL){
      return -1;
   }

   //variaveis aux
   int aux = 0;
   Imagem imgTemp;

   //percorre arquivo
   while (fread(&imgTemp, sizeof(Imagem), 1, pegarImagem) != 0){
      if(imgTemp.id == id){
         aux = 1; //achou
         printf("\nImagem encontrada!");
         break;
      }
   }
   //se nao encontrou imagem
   if (aux == 0){
      fclose(pegarImagem);
      return 0;
   }
   fseek(pegarImagem, (aux-1) * sizeof(Imagem), SEEK_SET);
   //altera os dados da imagem
   printf("\nInsira nome do novo proprietario: ");
   scanf("%s", imgTemp.proprietario); //proprietario
   struct tm tm =getSystemTime();
   imgTemp.data_criacao.dia = imgTemp.data_modificacao.dia = tm.tm_mday;
   imgTemp.data_criacao.mes = imgTemp.data_modificacao.mes = tm.tm_mon + 1;
   imgTemp.data_criacao.ano = imgTemp.data_modificacao.ano = tm.tm_year + 1900; //datas

   //salva alteracao
   fseek(pegarImagem, 0, SEEK_CUR);
   fwrite(&imgTemp, sizeof(Imagem), 1, pegarImagem);

   //fecha arquivo
   fclose(pegarImagem);
   return 1;

}
