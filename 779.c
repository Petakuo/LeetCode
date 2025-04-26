Sol1: 
int kthGrammar(int n, int k) {
    int len = 1;
    while(len < k){
        len *= 2;
    }
    int flip = 0;
    while(k > 1){
        len /= 2;
        if(k > len){
            flip++;
            k -= len;
        }
    }
    return flip%2;
}

Sol2: 
int kthGrammar(int n, int k) {
    if(n == 1) return 0;
    int half = 1 << (n-2);
    if(k > half) return !kthGrammar(n-1, k-half);
    else return kthGrammar(n-1, k);
}
