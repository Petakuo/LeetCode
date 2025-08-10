/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reverseSubmatrix(int** grid, int gridSize, int* gridColSize, int x, int y, int k, int* returnSize, int** returnColumnSizes) {
    for(int i = 0; i < k/2; i++){
        int topIdx = x+i;
        int bottomIdx = x+(k-1-i);
        for(int j = 0; j < k; j++){
            int colIdx = y+j;
            int temp = grid[topIdx][colIdx];
            grid[topIdx][colIdx] = grid[bottomIdx][colIdx];
            grid[bottomIdx][colIdx] = temp;
        }
    }
    *returnSize = gridSize;
    (*returnColumnSizes) = malloc(gridSize*sizeof(int));
    for(int i = 0; i < gridSize; i++){
        (*returnColumnSizes)[i] = *gridColSize;
    }
    return grid;
}
