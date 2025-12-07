Sol1: 
int countOdds(int low, int high){
    int a = 0;
    for(int i = low; i <= high; i++ ){
        a += (i%2);
    }
    return a;
}

Sol2: 
int countOdds(int low, int high){
    int ans = (high-low)/2;
    if(low%2 == 1 || high%2 == 1) ans++;
    return ans;
}
