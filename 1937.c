#define MAX(a, b) ((a) > (b) ? (a) : (b))

long long maxPoints(int** points, int pointsSize, int* pointsColSize) {
    int rows = pointsSize;
    int cols = *pointsColSize;
    long long* dp = (long long*)malloc(sizeof(long long) * cols);
    long long* left = (long long*)malloc(sizeof(long long) * cols);
    long long* right = (long long*)malloc(sizeof(long long) * cols);
    for (int j = 0; j < cols; j++){
        dp[j] = points[0][j];
    }
    for (int i = 1; i < rows; i++){
        left[0] = dp[0];
        for (int j = 1; j < cols; j++) {
            left[j] = MAX(left[j - 1] - 1, dp[j]);
        }
        right[cols - 1] = dp[cols - 1];
        for (int j = cols - 2; j >= 0; j--){
            right[j] = MAX(right[j + 1] - 1, dp[j]);
        }
        for (int j = 0; j < cols; j++){
            dp[j] = points[i][j] + MAX(left[j], right[j]);
        }
    }
    long long result = dp[0];
    for (int j = 0; j < cols; j++){
        result = MAX(result, dp[j]);
    }
    free(dp);
    free(left);
    free(right);
    return result;
}
