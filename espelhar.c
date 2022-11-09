/*
 * em linhas fixas, permutar col 1 com col n-1, col 2 com col n-2
 */
void espelhar(int **mat, int lin, int col)
{
    int aux;
    for (int j = 0; j < (col / 2); j++)
    { // para cada coluna
        for (int i = 0; i < lin; i++)
        {
            aux = mat[i][j];                   // copie a coluna esq. em aux
            mat[i][j] = mat[i][((col - 1) - j)]; // copia de coluna dir. para coluna esq.
            mat[i][((col - 1) - j)] = aux;       // copia de aux para coluna dir.
        }
    }
}
