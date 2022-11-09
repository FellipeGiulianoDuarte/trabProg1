#include "libTrabalho.h"
/*
 * semelhante a alocaString, mas aloca em relacao a numero de int lin e int col
 * lembrar de desalocar
 */
int **alocaMatrizImagem(int lin, int col)
{
    int **mat, i;
    // alocacao das linhas
    mat = (int **)malloc(lin * sizeof(int *));
    // aloca cada uma das linhas (vetores de col inteiros)
    for (i = 0; i < lin; i++)
    {
        mat[i] = (int *)malloc(col * sizeof(int));
        if (mat[i] == NULL)
        {
            printf("\nMemória insuficiente - função alocaMatrizImagem\n");
            desalocaMatrizImagem(mat, i, col);
            return NULL;
        }
    }
    if (mat == NULL)
    {
        free(mat);
        printf("\nMemória insuficiente - função alocaMatrizImagem\n");
        return NULL;
    }
    return mat;
}
