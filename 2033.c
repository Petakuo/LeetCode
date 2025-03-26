int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int minOperations(int** grid, int gridSize, int* gridColSize, int x) {
    int total = gridSize*(*gridColSize);
    int* arr = (int*)malloc(total*sizeof(int));
    int index = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < (*gridColSize); j++){
            arr[index++] = grid[i][j];
        }
    }
    qsort(arr, total, sizeof(int), cmp);
    int value = arr[total/2];
    int ans = 0;
    for(int i = 0; i < total; i++){
        int diff = abs(arr[i]-value)%x;
        if(diff == 0) ans+= abs(arr[i]-value)/x;
        else return -1;
    }
    return ans;
}
