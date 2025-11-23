int numberOfPoints(int** nums, int numsSize, int* numsColSize) {
    int ans = 0;
    int table[101] = {0};
    for(int i = 0; i < numsSize; i++){
        for(int j = nums[i][0]; j <= nums[i][1]; j++){
            if(table[j] == 0){
                table[j] = 1;
                ans++;
            }
        }
    }
    return ans;
}
