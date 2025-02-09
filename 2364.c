typedef struct {
    int key;
    int count;
    UT_hash_handle hh;
} hashTable;

long long countBadPairs(int* nums, int numsSize) {
    hashTable* total = NULL, *entry, *tmp;
    long long ans = 0;
    for(int i = numsSize-1; i >= 0; i--){
        int target = nums[i]-i;
        HASH_FIND_INT(total, &target, entry);
        if(!entry){
            entry = (hashTable*)malloc(sizeof(hashTable));
            entry->key = target;
            entry->count = 1;
            HASH_ADD_INT(total, key, entry);
            ans += numsSize-1-i;
        }
        else{
            ans += numsSize-1-i-entry->count;
            entry->count += 1;
        }
    }
    HASH_ITER(hh, total, entry, tmp){
        HASH_DEL(total, entry);
        free(entry);
    }
    return ans;
}
