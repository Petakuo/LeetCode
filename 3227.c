bool doesAliceWin(char* s) {
    for(int i = 0; i < strlen(s); i++){
        if((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u')) return 1;
    }
    return 0;
}
