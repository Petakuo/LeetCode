/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool IsPrime(int n){
    if(n == 2 || n == 3) return 1;
    if(n == 1 || n%2 == 0) return 0;
    for(int i = 3; i*i <= n; i += 2){
        if(n%i == 0) return 0;
    }
    return 1;
}

int* closestPrimes(int left, int right, int* returnSize) {
    int* ans = (int*)malloc(2*sizeof(int));
    *returnSize = 2;
    ans[0] = -1;
    ans[1] = -1;
    int P1 = 0, P2 = 0, gap = right-left+1;
    for(int i = left; i <= right; i++){
        if(IsPrime(i)){
            P1 = i;
            break;
        }
    }
    if(P1 == 0) return ans;
    if(P1 == 2){
        for(int i = P1+1; i <= right; i += 2){
            if(IsPrime(i)){
                P2 = i;
                int curGap = gap < P2-P1 ? gap : P2-P1;
                if(curGap < gap){
                    ans[0] = P1;
                    ans[1] = P2;
                    gap = curGap;
                }
                P1 = P2;
            }
        }
    }
    for(int i = P1+2; i <= right; i += 2){
        if(IsPrime(i)){
            P2 = i;
            int curGap = gap < P2-P1 ? gap : P2-P1;
            if(curGap < gap){
                ans[0] = P1;
                ans[1] = P2;
                gap = curGap;
            }
            P1 = P2;
        }
    }
    return ans;
}
