#include "libTrabalho.h"
/*
 * copia os valores de mat para matCopia
 */
void copiaMatrizImagem(int **mat, int **matCopia, int lin, int col)
{
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matCopia[i][j] = mat[i][j];
        }
    }
}
