int maxFreeTime(int eventTime, int k, int* startTime, int startTimeSize, int* endTime, int endTimeSize) {
    int interval = startTimeSize-1;
    int* val = (int*)calloc((interval+2), sizeof(int));
    val[0] = startTime[0]-0;
    val[interval+1] = eventTime-endTime[endTimeSize-1];
    for(int i = 1; i < interval+1; i++){
        val[i] = startTime[i]-endTime[i-1];
    }
    int left = 0, right = 0, ans = 0;
    for(right; right < k+1; right++){
        ans += val[right];
    }
    int cur = ans;
    while(right < interval+2){
        cur = cur+val[right++]-val[left++];
        ans = ans > cur ? ans : cur;
    }
    free(val);
    return ans;
}
