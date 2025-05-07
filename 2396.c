bool isPal(char* s){
    int len = strlen(s);
    for(int i = 0; i < len/2; i++){
        if(s[i] != s[len-1-i]) return 0;
    }
    return 1;
}

bool isStrictlyPalindromic(int n) {
    for(int b = 2; b <= n-2; b++){
        int temp = n, size = 0;
        while(temp){
            temp /= b;
            size++;
        }
        char* bNum = (char*)malloc((size+1)*sizeof(char));
        bNum[size] = '\0';
        size--;
        temp = n;
        while(temp){
            bNum[size--] = '0'+temp%b;
            temp /= b;
        }
        bool ans = isPal(bNum);
        free(bNum);
        if(!ans) return 0;
    }
    return 0;
}
