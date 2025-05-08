void markZero(char** grid, int i, int j, int gridSize, int gridColSize){
    if(i < 0 || i >= gridSize || j < 0 || j >= gridColSize || grid[i][j] == '0') return;
    grid[i][j] = '0';
    markZero(grid, i, j+1, gridSize, gridColSize);
    markZero(grid, i, j-1, gridSize, gridColSize);
    markZero(grid, i+1, j, gridSize, gridColSize);
    markZero(grid, i-1, j, gridSize, gridColSize);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int ans = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < (*gridColSize); j++){
            if(grid[i][j] == '1') ans++;
            markZero(grid, i, j, gridSize, (*gridColSize));
        }
    }
    return ans;
}
