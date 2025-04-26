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
