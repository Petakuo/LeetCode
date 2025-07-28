int countEven(int num) {
    int ans = 0;
    for(int i = 1; i <= num; i++){
        int temp = i, sum = 0;
        while(temp){
            sum += temp%10;
            temp /= 10;
        }
        if((sum&1) == 0) ans++;
    }
    return ans;
}
