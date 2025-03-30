int minimumChairs(char* s) {
    int len = strlen(s);
    int chairs = 0, person = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == 'E') person++;
        else if(s[i] == 'L') person--;
        if(person > chairs) chairs++;
    }
    return chairs;
}
