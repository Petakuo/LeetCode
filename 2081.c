bool isPal(long long n, int k){
    long long temp = n, count = 0;
    while(temp){
        temp /= k;
        count++;
    }
    char* s = (char*)malloc((count+1)*sizeof(char));
    s[count] = '\0';
    for(int i = 0; i < count; i++){
        s[i] = '0'+n%k;
        n /= k;
    }
    for(int i = 0; i < count/2; i++){
        if(s[i] != s[count-1-i]){
            free(s);
            return 0;
        }
    }
    free(s);
    return 1;
}

long long kMirror(int k, int n) {
    int left = 1, count = 0;
    long long ans = 0;
    while(count < n){
        int right = left*10;
        for(int parity = 0; parity < 2; parity++){
            for(int i = left; i < right && count < n; i++){
                long long fHalf = i;
                long long sHalf = (parity == 0 ? i/10 : i);
                while(sHalf > 0){
                    fHalf = fHalf*10+sHalf%10;
                    sHalf /= 10;
                }
                if(isPal(fHalf, k)){
                    count++;
                    ans += fHalf;
                }
            }
        }
        left = right;
    }
    return ans;
}
