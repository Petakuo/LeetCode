int findKthNumber(int n, int k) {
    long long x = 1;
    while(k > 1){
        long long count = 0;
        long long cur = x, node = 1;
        while(cur <= n){
            count += (n-cur+1) < node ? (n-cur+1) : node;
            cur *= 10;
            node *= 10;
        }
        if(k > count){
            k -= count;
            x++;
        }
        else{
            k--;
            x *= 10;
        }
    }
    return x;
}
