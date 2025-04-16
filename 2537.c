struct hashTable{
    int key;
    int count;
    UT_hash_handle hh;
};

long long countGood(int* nums, int numsSize, int k) {
    long long ans = 0, pair = 0;
    int left = 0, right = 0;
    struct hashTable *freq = NULL, *entry, *cur, *tmp;
    while(right < numsSize){
        HASH_FIND_INT(freq, &nums[right], entry);
        if(!entry){
            entry = malloc(sizeof(struct hashTable));
            entry->key = nums[right];
            entry->count = 0;
            HASH_ADD_INT(freq, key, entry);
        }
        pair += entry->count;
        (entry->count)++;
        while(pair >= k){
            ans += numsSize-right;
            HASH_FIND_INT(freq, &nums[left], entry);
            (entry->count)--;
            pair -= entry->count;
            left++;
        }
        right++;
    }
    HASH_ITER(hh, freq, cur, tmp){
        HASH_DEL(freq, cur);
        free(cur);
    }
    return ans;
}
