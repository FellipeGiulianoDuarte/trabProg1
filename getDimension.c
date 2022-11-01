#include "libTrabalho.h"
/*
 * imagem PGM tem 3 dados antes da imagem: tipo, num Colunas, num Linhas. registra altura por ponteiro e largura por int
 */
int getDimension(char nomeImagem[], int *pAltura){
	FILE *fileImg = fopen(nomeImagem, "r");
	if (fileImg == NULL){
      return -1;
   	}
	int largura;
	fscanf(fileImg, "%d");
	fscanf(fileImg, "%d", &largura);
	fscanf(fileImg, "%d", &pAltura);
	fclose(fileImg);
	return largura;
}
