int makeTheIntegerZero(int num1, int num2) {
    int ans = 1;
    while(1){
        long long guess = (long long)num1-(long long)num2*ans;
        if(guess < ans) return -1;
        if(ans >= __builtin_popcountll(guess)) return ans;
        ans++;
    }
}
