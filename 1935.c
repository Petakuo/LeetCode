Sol1: 
int canBeTypedWords(char* text, char* brokenLetters) {
    int ans = 0;
    for(int i = 0; text[i] != '\0'; i++){
        bool broken = 0;
        while(text[i] != ' ' && text[i] != '\0'){
            for(int j = 0; brokenLetters[j] != '\0'; j++){
                if(text[i] == brokenLetters[j]){
                    broken = 1;
                    break;
                }
            }
            i++;
        }
        if(!broken) ans++;
        if(text[i] == '\0') i--;
    }
    return ans;
}

Sol2: 
int canBeTypedWords(char* text, char* brokenLetters) {
    int ans = 0;
    int bitmask = 0;
    for(int i = 0; brokenLetters[i] != '\0'; i++){
        bitmask |= 1 << (brokenLetters[i]-'a');
    }
    for(int i = 0; text[i] != '\0'; i++){
        int wordmask = 0;
        while(text[i] != ' ' && text[i] != '\0'){
            wordmask |= 1 << (text[i]-'a');
            i++;
        }
        if((bitmask&wordmask) == 0) ans++;
        if(text[i] == '\0') i--;
    }
    return ans;
}
