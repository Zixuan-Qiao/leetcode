void rotate(int** matrix, int matrixSize, int* matrixColSize) {

    int i = 0;
    int j  = matrixSize - 1;
    while(i < j) {
        for(int n = 0; n < matrixSize; n++) {
            int temp = matrix[i][n];
            matrix[i][n] = matrix[j][n];
            matrix[j][n] = temp;
        }
        i++;
        j--;
    }

    for(i = 0; i < matrixSize; i++) {
        for(j = i + 1; j < matrixSize; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }   
    }
}