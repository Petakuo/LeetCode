bool IsSame(char* s, char* t, int len){
    for(int i = 0; i < len; i++){
        if(s[i] != t[i]) return 0;
    }
    return 1;
}

char* removeOccurrences(char* s, char* part) {
    int lenS = strlen(s);
    int lenP = strlen(part);
    int top = 0;
    for(int i = 0; i < lenS; i++){
        s[top++] = s[i];
        if((top >= lenP) && (IsSame(s+top-lenP, part, lenP))) top -= lenP;
    }
    s[top] = '\0';
    return s;
}
