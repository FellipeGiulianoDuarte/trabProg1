#include "libTrabalho.h"
/*
 * Abrir arquivo, para cada item de imagem salvo imprimir dados na tela
 */
/****** Completar *****/
void listaImagens(char arqFisicoImagensBase[]){
   //abre arquivo
   FILE *listarImagem = fopen(arqFisicoImagensBase,"rb");
   if (listarImagem == NULL){
      return -1;
   }
   Imagem imgTemp;
   //percorre arquivo
   while (fread(&imgTemp, sizeof(Imagem), 1, listarImagem) != 0){
      //printar dados na tela
      printf("\n\t====== Dados da imagem: ======\n");
      printf("\tNome: %s\n", imgTemp.nome);
      printf("\tId: %d\n", imgTemp.id);
      printf("\tTipo: %s\n", imgTemp.tipo);
      printf("\tTamanho (em bytes): %d\n", imgTemp.size);
      printf("\tDimensao (largura x altura): %d x %d\n", imgTemp.dimensao.largura, imgTemp.dimensao.altura);
      printf("\tProprietario: %s\n", imgTemp.proprietario);
      printf("\tData criacao: %d/%d/%d\n", imgTemp.data_criacao.dia, imgTemp.data_criacao.mes, imgTemp.data_criacao.ano);
      printf("\tData modificacao: %d/%d/%d\n", imgTemp.data_modificacao.dia, imgTemp.data_modificacao.mes, imgTemp.data_modificacao.ano);
      printf("\t==============================\n");
   }
   //fecha arquivo
   fclose(listarImagem);

}

