#define min(x, y) ((x) < (y) ? (x) : (y))

char* getSmallestString(char* s, int k) {
    int len = strlen(s);
    char* ans = malloc((len+1)*sizeof(char));
    strcpy(ans, s);
    for(int i = 0; i < len; i++){
        int dis = min(ans[i]-'a', 26-(ans[i]-'a'));
        if(k >= dis){
            ans[i] = 'a';
            k -= dis;
        }
        else if(k > 0){
            ans[i] -= k;
            if(ans[i]-'a' < 0) ans += 26;
            break;
        }
    }
    return ans;
}
