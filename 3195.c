int minimumArea(int** grid, int gridSize, int* gridColSize) {
    int left = (*gridColSize)-1, right = 0, top = gridSize-1, bottom = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < (*gridColSize); j++){
            if(grid[i][j] == 1){
                if(j < left) left = j;
                if(j > right) right = j;
                if(i < top) top = i;
                if(i > bottom) bottom = i;
            }
        }
    }
    return (right-left+1)*(bottom-top+1);
}
