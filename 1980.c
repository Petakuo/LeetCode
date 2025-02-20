bool backtracking(char** nums, int numsSize, int index, char* s){
    if(index == numsSize){
        for(int i = 0; i < numsSize; i++){
            if(!strcmp(s, nums[i])) return 0;
        }
        return 1;
    }
    for(int i = 0; i < 2; i++){
        s[index] = i+'0';
        if(backtracking(nums, numsSize, index+1, s)) return 1;
    }
    return 0;
}

char* findDifferentBinaryString(char** nums, int numsSize) {
    char* s = (char*)malloc((numsSize+1)*sizeof(char));
    s[numsSize] = '\0';
    if(backtracking(nums, numsSize, 0, s)) return s;
    return 0;
}
