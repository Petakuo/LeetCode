int sumOddLengthSubarrays(int* arr, int arrSize) {
    int sum = 0;
    for(int i = 1; i <= arrSize; i += 2){
        for(int j = 0; j <= arrSize-i; j++){
            for(int k = j; k < i+j; k++){
                sum += arr[k];
            }
        }
    }
    return sum;
}
