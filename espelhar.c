/*
 * em linhas fixas, permutar col 1 com col n-1, col 2 com col n-2
 */
void espelhar (int **mat, int lin, int col){
   int vetAux[lin];
   for (int i = 0; i < (col/2); i++){ //para cada coluna
      for (int j = 0; j < lin; j++){ 
         vetAux[j] = mat[i][j]; //copie a coluna esq. em aux
         mat[i][j] = mat[i][(col-1)-i]; //copia de coluna dir. para coluna esq.
         mat[i][(col-1)-i] = vetAux[j]; //copia de aux para coluna dir.
      }
   }
}
