void add(char s, int* table, int* count){
    if(s == 'a') table[0]++;
    else if(s == 'e') table[1]++;
    else if(s == 'i') table[2]++;
    else if(s == 'o') table[3]++;
    else if(s == 'u') table[4]++;
    else (*count)++;
}

void minus(char s, int* table, int* count){
    if(s == 'a') table[0]--;
    else if(s == 'e') table[1]--;
    else if(s == 'i') table[2]--;
    else if(s == 'o') table[3]--;
    else if(s == 'u') table[4]--;
    else (*count)--;
}

bool check(int* table){
    for(int i = 0; i < 5; i++){
        if(table[i] < 1) return 0;
    }
    return 1;
}

long long validK(char* word, int k){
    int len = strlen(word);
    int count = 0, left = 0, right = 0;
    long long ans = 0;
    int* table = (int*)calloc(5, sizeof(int));
    while(right < len){
        add(word[right], table, &count);
        while(check(table) && count >= k){
            ans += len-right;
            minus(word[left], table, &count);
            left++;
        }
        right++;
    }
    free(table);
    return ans;
}

long long countOfSubstrings(char* word, int k) {
    return validK(word, k)-validK(word, k+1);
}
