int cmp(const void* a, const void* b){
    return (*(int**)a)[1]-(*(int**)b)[1];
}

int maxValue(int** events, int eventsSize, int* eventsColSize, int k) {
    qsort(events, eventsSize, sizeof(int*), cmp);
    int** dp = (int**)malloc((eventsSize+1)*sizeof(int*));
    for(int i = 0; i <= eventsSize; i++){
        dp[i] = (int*)calloc(k+1, sizeof(int));
    }
    for(int i = 1; i <= eventsSize; i++){
        for(int j = 1; j <= k; j++){
            int prev = -1;
            int left = 0, right = i-2;
            while(left <= right){
                int mid = left+(right-left)/2;
                if(events[mid][1] < events[i-1][0]){
                    left = mid+1;
                    prev = mid;
                }
                else if(events[mid][1] >= events[i-1][0]) right = mid-1;
            }
            int update = events[i-1][2]+(prev >= 0 ? dp[prev+1][j-1] : 0);
            dp[i][j] = dp[i-1][j] > update ? dp[i-1][j] : update;
        }
    }
    int ans = dp[eventsSize][k];
    for(int i = 0; i < eventsSize; i++){
        free(dp[i]);
    }
    free(dp);
    return ans;
}
