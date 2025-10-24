int isBalanced(int n){
    int freq[10] = {0};
    while(n){
        freq[n%10]++;
        n /= 10;
    }
    for(int i = 0; i < 10; i++){
        if(freq[i] > 0 && freq[i] != i) return 0;
    }
    return 1;
}

int nextBeautifulNumber(int n) {
    for(int i = n+1; i < 1224445; i++){
        if(isBalanced(i)) return i;
    }
    return 0;
}
