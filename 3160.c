/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int color;
    int count;
    UT_hash_handle hh
} hashTable;

int* queryResults(int limit, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* colored = (int*)calloc(limit+1, sizeof(int));
    hashTable* colorMap = NULL, *entry, *key;
    int* ans = (int*)malloc(queriesSize*sizeof(int));
    int distinct = 0;
    for(int i = 0; i < queriesSize; i++){
        int ball = queries[i][0];
        int newColor = queries[i][1];
        if(colored[ball] != 0){
            int oldColor = colored[ball];
            HASH_FIND_INT(colorMap, &oldColor, entry);
            if(entry) entry->count--;
            if(entry->count == 0){
                HASH_DEL(colorMap, entry);
                free(entry);
                distinct--;
            }
        }
        colored[ball] = newColor;
        HASH_FIND_INT(colorMap, &newColor, entry);
        if(!entry){
            entry = (hashTable*)malloc(sizeof(hashTable));
            entry->color = newColor;
            entry->count = 0;
            HASH_ADD_INT(colorMap, color, entry);
            distinct++;
        }
        entry->count++;
        ans[i] = distinct;
    }
    free(colored);
    HASH_ITER(hh, colorMap, entry, key){
        HASH_DEL(colorMap, entry);
        free(entry);
    }
    return ans;
}
