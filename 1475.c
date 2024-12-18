Sol1: 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    *returnSize = pricesSize;
    int* ans = (int*)malloc(pricesSize*sizeof(int));
    for(int i = 0; i < pricesSize; i++){
        int less = i+1;
        while(less < pricesSize && prices[less] > prices[i]){
            less++;
        }
        if(less < pricesSize){
            ans[i] = prices[i]-prices[less];
        }
        else ans[i] = prices[i];
    }
    return ans;
}

Sol2: 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    *returnSize = pricesSize;
    int* ans = (int*)malloc(pricesSize*sizeof(int));
    int* stack = (int*)malloc(pricesSize*sizeof(int));
    int top = -1;
    for(int i = 0; i < pricesSize; i++){
        while(top >= 0 && prices[i] <= prices[stack[top]]){
            ans[stack[top]] = prices[stack[top]]-prices[i];
            top--;
        }
        top++;
        stack[top] = i;
    }
    while(top >= 0){
        ans[stack[top]] = prices[stack[top]];
        top--;
    }
    free(stack);
    return ans;
}
