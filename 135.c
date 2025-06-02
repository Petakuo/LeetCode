int candy(int* ratings, int ratingsSize) {
    if(ratingsSize == 1) return 1;
    int* candies = (int*)calloc(ratingsSize, sizeof(int));
    int ans = ratingsSize;
    for(int i = 1; i <= ratingsSize-1; i++){
        if(ratings[i] > ratings[i-1] && candies[i] <= candies[i-1]){
            candies[i] = candies[i-1]+1;
        }
    }
    for(int i = ratingsSize-2; i >= 0; i--){
        while(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]){
            candies[i] = candies[i+1]+1;
        }
    }
    for(int i = 0; i < ratingsSize; i++){
        ans += candies[i];
    }
    free(candies);
    return ans;
}
