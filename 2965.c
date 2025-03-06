/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int* ans = (int*)malloc(2*sizeof(int));
    *returnSize = 2;
    int size = gridSize*gridSize;
    int* table = (int*)calloc(size+1, sizeof(int));
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < (*gridColSize); j++){
            int num = grid[i][j];
            table[num]++;
            if(table[num] == 2) ans[0] = num;
        }
    }
    for(int i = 1; i <= size; i++){
        if(table[i] == 0) ans[1] = i;
    }
    return ans;
}
