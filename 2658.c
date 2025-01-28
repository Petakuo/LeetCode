int dfs(int** grid, int gridSize, int* gridColSize, int x, int y){
    int sum = 0;
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    if(grid[x][y] != 0){
        sum += grid[x][y];
        grid[x][y] = 0;
        for(int i = 0; i < 4; i++){
            int xx = x+direction[i][0];
            int yy = y+direction[i][1];
            if((xx >= 0) && (xx < gridSize) && (yy >= 0) && (yy < (*gridColSize))){
                sum += dfs(grid, gridSize, gridColSize, xx, yy);
            }
        }
    }
    return sum;
}

int findMaxFish(int** grid, int gridSize, int* gridColSize) {
    int max = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < (*gridColSize); j++){
            int now = dfs(grid, gridSize, gridColSize, i, j);
            max = max > now ? max : now;
        }
    }
    return max;
}
