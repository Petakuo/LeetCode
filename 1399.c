int countLargestGroup(int n) {
    int table[37] = {0};
    int max = 0;
    for(int i = 1; i <= n; i++){
        int temp = i, count = 0;
        while(temp){
            count += temp%10;
            temp /= 10;
        }
        table[count]++;
        max = table[count] > max ? table[count] : max;
    }
    int ans = 0;
    for(int i = 0; i < 37; i++){
        if(table[i] == max) ans++;
    }
    return ans;
}
