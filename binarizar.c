/*
 * analisa o item [i][j], se >= 127 vira 255 senao vira 0 (binariza)
 */
void binarizar (int **mat, int lin, int col){
	for (int i = 0; i < lin; i++){
		for (int j = 0; j < col; j++){
			((mat[i][j] >= 127) ? (mat[i][j] = 255) : (mat[i][j] = 0));
		}
	}
}
