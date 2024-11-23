Sol1:
bool isPowerOfFour(int n) {
    if(n <= 0) return 0;
    int zero = 0;
    int temp = n;
    while(temp){
        if((temp & 1) == 0) zero++;
        temp >>= 1;
    }
    return ((n&(n-1)) == 0) && (zero%2 == 0);
}

Sol2:
bool isPowerOfFour(int n) {
    return (n > 0) && ((n&(n-1)) == 0) && ((n&0xaaaaaaaa) == 0);
}
