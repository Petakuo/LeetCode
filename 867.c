/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int** ans = (int**)malloc((*matrixColSize)*sizeof(int*));
    for(int i = 0; i < (*matrixColSize); i++){
        ans[i] = malloc(matrixSize*sizeof(int));
    }
    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < (*matrixColSize); j++){
            ans[j][i] = matrix[i][j];
        }
    }
    *returnSize = (*matrixColSize);
    *returnColumnSizes = (int*)malloc((*matrixColSize)*sizeof(int));
    for(int i = 0; i < (*matrixColSize); i++){
        (*returnColumnSizes)[i] = matrixSize;
    }
    return ans;
}
