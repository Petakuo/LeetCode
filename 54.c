/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int** visit = (int**)malloc(matrixSize*sizeof(int*));
    for(int i = 0; i < matrixSize; i++){
        visit[i] = (int*)calloc((*matrixColSize), sizeof(int));
    }
    int total = matrixSize*(*matrixColSize);
    *returnSize = total;
    int* ans = (int*)malloc(total*sizeof(int));
    int row = 0, col = 0, index = 0;
    while(total){
        while(row < (*matrixColSize) && visit[col][row]  == 0){
            ans[index] = matrix[col][row];
            index++;
            visit[col][row] = 1;
            row++;
            total--;
        }
        row--;
        col++;
        while(col < matrixSize && visit[col][row] == 0){
            ans[index] = matrix[col][row];
            index++;
            visit[col][row] = 1;
            col++;
            total--;
        }
        col--;
        row--;
        while(row >= 0 && visit[col][row] == 0){
            ans[index] = matrix[col][row];
            index++;
            visit[col][row] = 1;
            row--;
            total--;
        }
        row++;
        col--;
        while(col >= 0 && visit[col][row] == 0){
            ans[index] = matrix[col][row];
            index++;
            visit[col][row] = 1;
            col--;
            total--;
        }
        col++;
        row++;
    }
    for(int i = 0; i < matrixSize; i++){
        free(visit[i]);
    }
    free(visit);
    return ans;
}
