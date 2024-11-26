long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    int negative = 0;
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < (*matrixColSize); j++){
            if(matrix[i][j] <= 0){
                matrix[i][j] *= -1;
                negative++;
            }
        }
    }
    long long sum = 0;
    int min = matrix[0][0];
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < (*matrixColSize); j++){
            sum += matrix[i][j];
            min = min < matrix[i][j] ? min : matrix[i][j];
        }
    }
    if(negative%2 == 0) return sum;
    return sum-2*min;
}
