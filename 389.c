char findTheDifference(char* s, char* t) {
    int ans = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        ans ^= s[i]^t[i];
    }
    ans ^= t[len];
    return (char)ans;
}
