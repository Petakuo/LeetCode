SOl1: 
typedef struct{
    char* s;
    int count;
    UT_hash_handle hh;
}hashTable;

int longestPalindrome(char** words, int wordsSize) {
    hashTable* freq = NULL, *entry, *temp;
    int same[26] = {0};
    int count = 0;
    for(int i = 0; i < wordsSize; i++){
        if(words[i][0] == words[i][1]){
            same[words[i][0]-'a']++;
        }
        else{
            char pal[3];
            pal[0] = words[i][1];
            pal[1] = words[i][0];
            pal[2] = '\0';
            HASH_FIND_STR(freq, pal, entry);
            if(!entry){
                entry = (hashTable*)malloc(sizeof(hashTable));
                entry->s = strdup(words[i]);
                HASH_ADD_STR(freq, s, entry);
            }
            else{
                count += 4;
                HASH_DEL(freq, entry);
                free(entry->s);
                free(entry);
            }
        }
    }
    HASH_ITER(hh, freq, entry, temp){
            HASH_DEL(freq, entry);
            free(entry->s);
            free(entry);
    }
    for(int i = 0; i < 26; i++){
        if(same[i] > 1){
            count += 2*((same[i]&1) == 0 ? same[i] : same[i]-1);
            same[i] = (same[i]&1) == 0 ? 0 : 1;
        }
    }
    for(int i = 0; i < 26; i++){
        if(same[i] == 1){
            count += 2;
            break;
        }
    }
    return count;
}

Sol2: 
int longestPalindrome(char** words, int wordsSize) {
    int table[26][26] = {0};
    int count = 0;
    for(int i = 0; i < wordsSize; i++){
        int a = words[i][0]-'a', b = words[i][1]-'a';
        if(table[b][a] == 0) table[a][b]++;
        else{
            count += 4;
            table[b][a]--;
        }
    }
    for(int i = 0; i < 26; i++){
        if(table[i][i] > 0){
            count += 2;
            break;
        }
    }
    return count;
}
