bool guessEachChildGet(int* candies, int candiesSize, long long k, int guess){
    long long child = 0;
    for(int i = 0; i < candiesSize; i++){
        child += candies[i]/guess;
        if(child >= k) return 1;
    }
    return 0;
}

int maximumCandies(int* candies, int candiesSize, long long k) {
    int max = 0;
    for(int i = 0; i < candiesSize; i++){
        max = max > candies[i] ? max : candies[i];
    }
    int min = 1;
    while(min <= max){
        int mid = min+(max-min)/2;
        if(guessEachChildGet(candies, candiesSize, k, mid)){
            min = mid+1;
        }
        else max = mid-1;
    }
    return max;
}
