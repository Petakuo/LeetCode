Sol1: 
bool check(int* nums, int numsSize) {
    int rotate = 0, rotaIndex = 0;
    for(int i = 0; i < numsSize-1; i++){
        if(nums[i] > nums[i+1]){
            rotate++;
            rotaIndex = i;
        }
        if(rotate == 2) return 0;
    }
    if(rotate == 0) return 1;
    int temp[numsSize];
    for(int i = 0; i < numsSize; i++){
        temp[i] = nums[(i+1+rotaIndex)%numsSize];
    }
    for(int i = 0; i < numsSize-1; i++){
        if(temp[i] > temp[i+1]) return 0;
    }
    return 1;
}

Sol2: 
bool check(int* nums, int numsSize) {
    int rotate = 0;
    if(nums[numsSize-1] > nums[0]) rotate++;
    for(int i = 0; i < numsSize-1; i++){
        if(nums[i] > nums[i+1]) rotate++;
        if(rotate == 2) return 0;
    }
    return 1;
}
