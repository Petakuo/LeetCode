void dfs(int** grid, int gridSize, int gridColSize, int i, int j, int time){
    if(i < 0 || i >= gridSize || j < 0 || j >= gridColSize || grid[i][j] == 0) return;
    if(grid[i][j] == 1 || grid[i][j] >= time){
        grid[i][j] = time;
        dfs(grid, gridSize, gridColSize, i+1, j, time+1);
        dfs(grid, gridSize, gridColSize, i-1, j, time+1);
        dfs(grid, gridSize, gridColSize, i, j+1, time+1);
        dfs(grid, gridSize, gridColSize, i, j-1, time+1);
    }
}

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < (*gridColSize); j++){
            if(grid[i][j] == 2) dfs(grid, gridSize, (*gridColSize), i, j, 2);
        }
    }
    int max = 2;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < (*gridColSize); j++){
            if(grid[i][j] == 1) return -1;
            else max = max < grid[i][j] ? grid[i][j] : max;
        }
    }
    return max-2;
}
