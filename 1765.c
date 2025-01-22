/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** highestPeak(int** isWater, int isWaterSize, int* isWaterColSize, int* returnSize, int** returnColumnSizes) {
    int** ans = (int**)malloc(isWaterSize*sizeof(int*));
    for(int i = 0; i < isWaterSize; i++){
        ans[i] = (int*)malloc((*isWaterColSize)*sizeof(int));
    }
    int* queueX = (int*)malloc(isWaterSize*(*isWaterColSize)*sizeof(int));
    int* queueY = (int*)malloc(isWaterSize*(*isWaterColSize)*sizeof(int));
    int head = 0, tail = 0;
    for(int i = 0; i < isWaterSize; i++){
        for(int j = 0; j < (*isWaterColSize); j++){
            if(isWater[i][j] == 1){
                queueX[tail] = i;
                queueY[tail] = j;
                tail++;
                ans[i][j] = 0;
            }
            else ans[i][j] = -1;
        }
    }
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(head < tail){
        int x = queueX[head];
        int y = queueY[head];
        head++;
        for(int k = 0; k < 4; k++){
            int xx = x+direction[k][0];
            int yy = y+direction[k][1];
            if(xx >= 0 && xx < isWaterSize && yy >= 0 && yy < (*isWaterColSize) && ans[xx][yy] == -1){
                ans[xx][yy] = ans[x][y]+1;
                queueX[tail] = xx;
                queueY[tail] = yy;
                tail++;
            }
        }
    }
    *returnSize = isWaterSize;
    *returnColumnSizes = (int*)malloc(isWaterSize*sizeof(int));
    for(int i = 0; i < isWaterSize; i++){
        (*returnColumnSizes)[i] = (*isWaterColSize);
    }
    return ans;
}
