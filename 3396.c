bool check(int* arr, int size){
    for(int i = 0; i < size; i++){
        if(arr[i] > 1) return 0;
    }
    return 1;
}

int minimumOperations(int* nums, int numsSize) {
    int arr[101] = {0};
    for(int i = 0; i < numsSize; i++){
        arr[nums[i]]++;
    }
    if(check(arr, 101)) return 0;
    int i = 0, count = 0;
    while(i < numsSize){
        if(i+2 < numsSize){
            arr[nums[i]]--;
            arr[nums[i+1]]--;
            arr[nums[i+2]]--;
            count++;
            if(check(arr, 101)) return count;
        }
        i += 3;
    }
    return count+1;
}
