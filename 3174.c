bool IsDigit(char s){
    if((s == '0') || (s == '1') || (s == '2') || (s == '3') || (s == '4') || (s == '5') || (s == '6') || (s == '7') || (s == '8') || (s == '9')) return 1;
    return 0;
}

char* clearDigits(char* s) {
    int top = 0;
    for(int i = 0; i < strlen(s); i++){
        if(IsDigit(s[i])){
            if(top > 0) top--;
        }
        else{
            s[top] = s[i];
            top++;
        }
    }
    s[top] = '\0';
    return s;
}
