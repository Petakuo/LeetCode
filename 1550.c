bool threeConsecutiveOdds(int* arr, int arrSize) {
    int count = 0;
    for(int i = 0; i < arrSize; i++){
        if((arr[i]&1) == 1) count++;
        else count = 0;
        if(count == 3) return 1;
    }
    return 0;
}
