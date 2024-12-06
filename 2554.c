int maxCount(int* banned, int bannedSize, int n, int maxSum) {
    int Banned[n+1];
    for(int i = 0; i < (n+1); i++){
        Banned[i] = 0;
    }
    for(int i = 0; i < bannedSize; i++){
        if(banned[i] <= n) Banned[banned[i]] = 1;
    }
    int i = 1, max = 0, count = 0;
    while(i <= n){
        while(i <= n && Banned[i] == 1){
            i++;
        }
        if(i > n || max+i > maxSum) return count;
        max += i;
        count++;
        i++;
    }
    return count;
}
