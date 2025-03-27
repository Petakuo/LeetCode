typedef struct{
    int val;
    int count;
    UT_hash_handle hh;
}hashTable;

int minimumIndex(int* nums, int numsSize) {
    hashTable* table = NULL, *entry, *tmp;
    int max = 0, num = 0;
    for(int i = 0; i < numsSize; i++){
        HASH_FIND_INT(table, &nums[i], entry);
        if(!entry){
            entry = (hashTable*)malloc(sizeof(hashTable));
            entry->val = nums[i];
            entry->count = 1;
            HASH_ADD_INT(table, val, entry);
        }
        else{
            entry->count++;
        }
        if(entry->count > max){
            max = entry->count;
            num = entry->val;
        }
    }
    HASH_ITER(hh, table, entry, tmp){
        HASH_DEL(table, entry);
        free(entry);
    }
    int count = 0, left = 1, right = numsSize-1;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] == num){
            count++;
        }
        if(2*count > left && 2*(max-count) > right) return i;
        left++;
        right--;
    }
    return -1;
}
