int tupleSameProduct(int* nums, int numsSize) {
    int ans = 0;
    int* table = (int*)calloc(100000001, sizeof(int));
    for(int i = 0; i < numsSize; i++){
        for(int j = i+1; j < numsSize; j++){
            int temp = nums[i]*nums[j];
            if(table[temp] == 0) table[temp]++;
            else ans += table[temp]++;
        }
    }
    free(table);
    return ans*8;
}
