char* makeFancyString(char* s) {
    int idx = 1, count = 1;
    for(int i = 1; s[i] != '\0'; i++){
        if(s[i] == s[i-1]) count++;
        else count = 1;
        if(count < 3){
            s[idx] = s[i];
            idx++;
        }
    }
    s[idx] = '\0';
    return s;
}
