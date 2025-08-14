char* largestGoodInteger(char* num) {
    char* s = (char*)malloc(4*sizeof(char));
    s[3] = '\0';
    s[0] = '0'-1;
    int len = strlen(num);
    for(int i = 0; i < len-2; i++){
        if(num[i] == num[i+1] && num[i] == num[i+2]){
            if(num[i] >= s[0]){
                s[0] = num[i];
                s[1] = num[i];
                s[2] = num[i];
                i += 2;
            }
        }
    }
    if(s[0] == '0'-1) s[0] = '\0';
    return s;
}
