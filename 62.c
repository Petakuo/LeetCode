int uniquePaths(int m, int n) {
    m--;
    n--;
    int sum = m+n;
    int max = m > n ? m : n;
    int min = m > n ? n : m;
    double ans = 1;
    for(int i = max+1; i <= sum; i++){
        ans *= i;
    }
    for(int i = min; i > 1; i--){
        ans /= i;
    }
    return ans;
}
