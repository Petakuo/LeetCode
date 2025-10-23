bool hasSameDigits(char* s) {
    int round = strlen(s)-2, each = strlen(s)-1;
    for(int i = 0; i < round; i++){
        for(int j = 0; j < each; j++){
            s[j] = (s[j]-'0'+s[j+1]-'0')%10+'0';
        }
        each--;
    }
    if(s[0] == s[1]) return 1;
    return 0;
}
