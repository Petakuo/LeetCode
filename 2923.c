int findChampion(int** grid, int gridSize, int* gridColSize) {
    for(int i = 0; i < gridSize; i++){
        int count = 0;
        for(int j = 0; j < (*gridColSize); j++){
            count += grid[i][j];
        }
        if(count == (*gridColSize)-1) return i;
    }
    return 0;
}
