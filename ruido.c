#include "libTrabalho.h"
/*
 * o ruído não deve ultrapassar um valor de 100 e deve
 * ser gerado pela função rand(), o pixel adicionado ao ruído não pode ser menor que 0 nem maior
 * que 255
 * funcao gera valor, analisa e define qual valor o pixel tera
 */
void ruido(int **mat, int lin, int col)
{
    srand(time(NULL));
    int auxRand;
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            auxRand = rand() % 101;
            (((mat[i][j] + auxRand) > 255) ? (mat[i][j] = 255) : (mat[i][j] += auxRand)); // se for estourar 255 mantem 255
        }
    }
}