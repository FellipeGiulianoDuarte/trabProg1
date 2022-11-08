#include "libTrabalho.h"
/*
 * le nomeArqEntrada como argumento da main e retorna ponteiro de ponteiro
 * para a matriz preenchida com os valores de cinza
 */
int **leArquivoImagem (char *nomeArqEntrada, char *tipo, int *lin, int *col, int *maxval){
    FILE *arq = fopen(nomeArqEntrada, "r");
    if (arq == NULL){
        printf("\nErro ao abrir arquivo - leArquivoImagem.\n");
        return NULL;
    }
    fscanf(arq, "%s", tipo);
    fscanf(arq, "%d", col);
    fscanf(arq, "%d", lin);
    fscanf(arq, "%d", maxval);
    int **mat = alocaMatrizImagem(*lin, *col);
    if (mat == NULL){
        printf("\nErro ao alocar mat imagem - leArquivoImagem.\n");
        return NULL;
    }
    for (int i = 0; i < *lin; i++){
        for (int j = 0; j < *col; j++){
            fscanf(arq, "%d", &mat[i][j]);
        }
    }
    fclose(arq);
    return mat;
}

