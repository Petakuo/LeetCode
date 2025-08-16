int maximum69Number (int num) {
    char* cnum = (char*)malloc(5*sizeof(char));
    int idx = 0;
    while(num){
        cnum[idx++] = '0'+num%10;
        num /= 10;
    }
    cnum[idx] = '\0';
    for(int i = idx-1; i >= 0; i--){
        if(cnum[i] == '6'){
            cnum[i] = '9';
            break;
        }
    }
    for(int i = idx-1; i >= 0; i--){
        num = num*10+cnum[i]-'0';
    }
    free(cnum);
    return num;
}
