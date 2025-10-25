int totalMoney(int n) {
    int ans = 0, base = 1;
    while(n){
        for(int i = 0; i < 7; i++){
            if(n <= 0) break;
            ans += base+i;
            n--;
        }
        base++;
    }
    return ans;
}
