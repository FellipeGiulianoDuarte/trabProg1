#include "libTrabalho.h"
/*
 * verifica se arquivo existe, verifica se já está cadastrado; caso seja possivel, cadastra imagem e grava informacao da imagem
 */
int cadastraImagem(char arqFisicoImagensBase[], char nomeImagem[]){
   //verifica se é possivel gravar imagem
   if(!verificaExistenciaDeImagem(nomeImagem)){
      printf("\nImagem inexistente no diretorio\n");
      return -1;
   }
   if (verificaCadastro(arqFisicoImagensBase, nomeImagem) != 0){
      //arrumar criacao de arquivo
      printf("\nImagem ja cadastrada\n");
      return 1;
   }
   
   //bloco de cadastrar Imagem
   Imagem img;
   strcpy(img.nome, nomeImagem); //nome imagem
   img.id = getLastId(arqFisicoImagensBase)+1; //id
   getExtension(nomeImagem, img.tipo); //extension
   img.size = getSize(nomeImagem); //size
   img.dimensao.largura = getDimension(nomeImagem, img.dimensao.altura); //dimension
   printf("\nInsira nome do proprietario: ");
   scanf("%s", img.proprietario); //proprietario
   struct tm tm =getSystemTime();
   img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
   img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
   img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900; //datas
   
   //gravaInfoImagem
   if(gravaInfoImagem(arqFisicoImagensBase, img)){
      printf("\nImagem cadastrada com sucesso! id = %d", img.id);
   }else{
      printf("\nErro ao gravar info imagem");
   }
   return 0;
}
