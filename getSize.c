#include "libTrabalho.h"
//implementada por default
/*
 * Captura e retornar o tamanho da imagem (em bytes)
 */
int getSize(char nomeImagem[]){
	int size;
	struct stat st;
	stat(nomeImagem, &st);
	size = st.st_size;
	return size;	
}
