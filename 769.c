int maxChunksToSorted(int* arr, int arrSize) {
    int sum = 0, indexsum = 0, ans = 0;
    for(int i = 0; i < arrSize; i++){
        sum += arr[i];
        indexsum += i;
        ans += (sum == indexsum);
    }
    return ans;
}
