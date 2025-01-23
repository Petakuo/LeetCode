int countServers(int** grid, int gridSize, int* gridColSize) {
    int* row = (int*)calloc(gridSize, sizeof(int));
    int* col = (int*)calloc(*gridColSize, sizeof(int));
    int ans = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < (*gridColSize); j++){
            if(grid[i][j] == 1){
                row[i]++;
                col[j]++;
                ans++;
            }
        }
    }
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < (*gridColSize); j++){
            if(grid[i][j] == 1 && row[i] == 1 && col[j] == 1) ans--;
        }
    }
    return ans;
}
