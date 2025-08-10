int countDigit(int n){
    int count = 0;
    while(n){
        n /= 10;
        count++;
    }
    return count;
}

bool reorderedPowerOf2(int n) {
    long test = 1, d = countDigit(n);
    while(countDigit(test) != d){
        test *= 2;
    }
    while(countDigit(test) == d){
        int table[11] = {0};
        int temp1 = n;
        long temp2 = test;
        for(int i = 0; i < d; i++){
            table[temp1%10]++;
            temp1 /= 10;
        }
        for(int i = 0; i < d; i++){
            table[temp2%10]--;
            temp2 /= 10;
        }
        int isZero = 1;
        for(int i = 0; i < 11; i++){
            isZero &= (table[i] == 0);
        }
        if(isZero == 1) return 1;
        else test *= 2;
    }
    return 0;
}
