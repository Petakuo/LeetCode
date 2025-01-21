#define max(a, b) (a > b ? a : b)
#define min(a, b) (a > b ? b : a)

long long gridGame(int** grid, int gridSize, int* gridColSize) {
    long long upSum = 0, downSum = 0;
    for(int i = 1; i < (*gridColSize); i++){
        upSum += grid[0][i];
    }
    long long ans = upSum;
    for(int i = 0; i < (*gridColSize)-1; i++){
        upSum -= grid[0][i+1];
        downSum += grid[1][i];
        ans = min(ans, max(upSum, downSum));
    }
    return ans;
}
