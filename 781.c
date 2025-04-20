struct hashTable{
    int key;
    int count;
    UT_hash_handle hh;
};

int numRabbits(int* answers, int answersSize) {
    struct hashTable *table = NULL, *entry, *cur, *tmp;
    for(int i = 0; i < answersSize; i++){
        HASH_FIND_INT(table, &answers[i], entry);
        if(!entry){
            entry = malloc(sizeof(struct hashTable));
            entry->key = answers[i];
            entry->count = 1;
            HASH_ADD_INT(table, key, entry);
        }
        else{
            (entry->count)++;
        }
    }
    int ans = 0;
    HASH_ITER(hh, table, cur, tmp){
        int groupSize = (cur->key)+1;
        int needGroup = (cur->count)%groupSize == 0 ? (cur->count)/groupSize : (cur->count)/groupSize+1;
        ans += groupSize*needGroup;
    }
    HASH_ITER(hh, table, cur, tmp){
        HASH_DEL(table, cur);
        free(cur);
    }
    return ans;
}
