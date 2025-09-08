/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool check(int n){
    while(n){
        if(n%10 == 0) return 0;
        n /= 10;
    }
    return 1;
}

int* getNoZeroIntegers(int n, int* returnSize) {
    int* ans = (int*)malloc(2*sizeof(int));
    *returnSize = 2;
    for(int i = 1; i <= n/2; i++){
        if(check(i) && check(n-i)){
            ans[0] = i;
            ans[1] = n-i;
            return ans;
        }
    }
    return 0;
}
