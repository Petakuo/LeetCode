char* countAndSay(int n) {
    if(n == 1){
        char* one = (char*)malloc(2*sizeof(char));
        one[0] = '1';
        one[1] = '\0';
        return one;
    }
    char* prev = countAndSay(n-1);
    int len = strlen(prev);
    char* ans = (char*)malloc((len*2+1)*sizeof(char));
    int i = 0, index = 0;
    while(i < len){
        int count = 1;
        while((i+1 < len) && (prev[i] == prev[i+1])){
            count++;
            i++;
        }
        ans[index++] = '0'+count;
        ans[index++] = prev[i];
        i++;
    }
    free(prev);
    ans[index] = '\0';
    return ans;
}
