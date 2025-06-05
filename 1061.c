int find(int* group, int x){
    if(group[x] != x) group[x] = find(group, group[x]);
    return group[x];
}

void Union(int* group, int x, int y){
    int a = find(group, x);
    int b = find(group, y);
    if(a == b) return;
    else if(a > b) group[a] = b;
    else group[b] = a;
}

char* smallestEquivalentString(char* s1, char* s2, char* baseStr) {
    int group[26];
    for(int i = 0; i < 26; i++){
        group[i] = i;
    }
    int len = strlen(s1);
    for(int i = 0; i < len; i++){
        Union(group, s1[i]-'a', s2[i]-'a');
    }
    len = strlen(baseStr);
    char* ans = (char*)malloc((len+1)*sizeof(char));
    for(int i = 0; i < len; i++){
        int root = find(group, baseStr[i]-'a');
        ans[i] = root+'a';
    }
    ans[len] = '\0';
    return ans;
}
