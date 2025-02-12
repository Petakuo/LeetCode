typedef struct{
    int key;
    int max;
    int max2;
    UT_hash_handle hh
}hashTable;

int maximumSum(int* nums, int numsSize) {
    int ans = -1;
    hashTable* table = NULL, *entry, *tmp;
    for(int i = 0; i < numsSize; i++){
        int temp = nums[i], digitSum = 0;
        while(temp != 0){
            digitSum += temp%10;
            temp /= 10;
        }
        HASH_FIND_INT(table, &digitSum, entry);
        if(!entry){
            entry = (hashTable*)malloc(sizeof(hashTable));
            entry->key = digitSum;
            entry->max = nums[i];
            entry->max2 = 0;
            HASH_ADD_INT(table, key, entry);
        }
        else{
            temp = nums[i];
            if(temp > entry->max){
                entry->max2 = entry->max;
                entry->max = temp;
            }
            else if(temp > entry->max2) entry->max2 = temp;
            ans = ans > entry->max+entry->max2 ? ans : entry->max+entry->max2;
        }
    }
    HASH_ITER(hh, table, entry, tmp){
        HASH_DEL(table, entry);
        free(entry);
    }
    return ans;
}
