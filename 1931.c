#define MOD 1000000007

int dfs(int m, int n, int i, int j, int cur, int prev, int dp[][1024]) {
    if (i == m) return dfs(m, n, 0, j+1, 0, cur, dp);
    if (j == n) return 1;
    if (i == 0 && dp[j][prev]) return dp[j][prev];
    int res = 0;
    int up = (i == 0) ? 0 : ((cur >> ((i-1)*2))&3);
    int left = (prev >> (i * 2)) & 3;
    for (int k = 1; k <= 3; k++) {
        if (k != left && k != up) {
            int new_cur = cur+(k << (i * 2));
            res = (res+dfs(m, n, i+1, j, new_cur, prev, dp)) % MOD;
        }
    }
    if (i == 0) dp[j][prev] = res;
    return res;
}

int colorTheGrid(int m, int n) {
    int dp[1001][1024] = {0};
    return dfs(m, n, 0, 0, 0, 0, dp);
}
