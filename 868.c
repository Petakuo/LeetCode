int binaryGap(int n) {
    int count = 0;
    int max = 0;
    while((n & 1) == 0){
        n >>= 1;
    }
    if(n == 1) return 0;
    if(n){
        n >>= 1;
        count++;
    }
    while(n){
        if((n & 1) == 0){
            count++;
            n >>= 1;
        }
        else if((n & 1) == 1){
            count++;
            max = max > count ? max : count;
            n >>= 1;
            count = 1;
        }
    }
    return max-1;
}
