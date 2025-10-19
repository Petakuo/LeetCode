char* findLexSmallestString(char* s, int a, int b) {
    int len = strlen(s);
    int visit[len];
    memset(visit, 0, sizeof(visit));
    char* ans = (char*)calloc(len+1, sizeof(char));
    strcpy(ans, s);
    char str[len*2+1];
    sprintf(str, "%s%s", s, s);
    for(int i = 0; visit[i] == 0; i = (i+b)%len){
        visit[i] = 1;
        for(int j = 0; j < 10; j++){
            int kMax = (b&1) == 0 ? 0 : 9;
            for(int k = 0; k <= kMax; k++){
                char temp[len+1];
                strncpy(temp, str+i, len);
                temp[len] = '\0';
                for(int l = 1; l < len; l += 2){
                    temp[l] = '0'+(temp[l]-'0'+j*a)%10;
                }
                for(int l = 0; l < len; l += 2){
                    temp[l] = '0'+(temp[l]-'0'+k*a)%10;
                }
                if(strcmp(temp, ans) < 0) strcpy(ans, temp);
            }
        }
    }
    return ans;
}
