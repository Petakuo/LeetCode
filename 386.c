/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(int now, int n, int* ans, int* idx){
    if(now > n) return;
    ans[(*idx)++] = now;
    for(int i = 0; i <= 9; i++){
        int next = now*10+i;
        if(next > n) return;
        dfs(next, n, ans, idx);
    }
}

int* lexicalOrder(int n, int* returnSize) {
    int* ans = (int*)malloc(n*sizeof(int));
    *returnSize = n;
    int idx = 0;
    for(int i = 1; i <= 9; i++){
        dfs(i, n, ans, &idx);
    }
    return ans;
}
