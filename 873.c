typedef struct{
    int index;
    int value;
    UT_hash_handle hh;
} hashtable;

int lenLongestFibSubseq(int* arr, int arrSize) {
    int dp[arrSize][arrSize];
    memset(dp, 0, sizeof(dp));
    hashtable* table = NULL, *entry, *temp;
    for(int i = 0; i < arrSize; i++){
        entry = (hashtable*)malloc(sizeof(hashtable));
        entry->index = arr[i];
        entry->value = i;
        HASH_ADD_INT(table, index, entry);
    }
    int ans = 0;
    for(int i = 0; i < arrSize; i++){
        for(int j = 0; j < i; j++){
            int find = arr[i]-arr[j];
            HASH_FIND_INT(table, &find, entry);
            if(!entry || entry->value >= j) continue;
            dp[j][i] = (dp[entry->value][j] == 0) ? 3 : dp[entry->value][j]+1;
            ans = ans > dp[j][i] ? ans : dp[j][i];
        }
    }
    HASH_ITER(hh, table, entry, temp){
        HASH_DEL(table, entry);
        free(entry);
    }
    return ans;
}
