bool isPowerOfThree(int n) {
    if(n <= 0) return 0;
    int base = 1;
    while(base < n && base < INT_MAX/3){
        base *= 3;
    }
    return base == n;
}
