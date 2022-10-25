/*
 * todo pixel 255 vira 0, todo pixel 0 vira 255, um pixel x vira 255 - x
 percorrer a matriz alterando valores
 */
void negativo (int **mat, int lin, int col){
	for (int i = 0; i < lin; i++){
		for (int j = 0; j < col; j++){
			mat[i][j] = (255 - mat[i][j]);
		}	
	}
}