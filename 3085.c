int cmp(const void*a, const void* b){
    return *(int*)a-*(int*)b;
}

int minimumDeletions(char* word, int k) {
    int table[26] = {0};
    int len = strlen(word);
    for(int i = 0; i < len; i++){
        table[word[i]-'a']++;
    }
    qsort(table, 26, sizeof(int), cmp);
    int min = 0, minIdx = 0, max = 0, maxIdx = 0;
    for(int i = 0; i < 26; i++){
        if(min == 0 && table[i] != 0){
            min = table[i];
            minIdx = i;
        }
        if(table[i] >= max){
            max = table[i];
            maxIdx = i;
        }
    }
    int ans = INT_MAX;
    for(int i = min; i <= max; i++){
        int cur = 0;
        for(int j = minIdx; j <= maxIdx; j++){
            if(table[j] < i) cur += table[j];
            if(table[j] > i+k) cur += (table[j]-i-k);
        }
        ans = cur < ans ? cur : ans;
    }
    return ans;
}
