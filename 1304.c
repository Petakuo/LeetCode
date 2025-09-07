/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize) {
    int* ans = (int*)malloc(n*sizeof(int));
    *returnSize = n;
    int idx = 0;
    for(int i = 1; i <= n/2; i++){
        ans[idx++] = i;
        ans[idx++] = (-1)*i;
    }
    if((n&1) == 1) ans[idx] = 0;
    return ans;
}
