int numOfSubarrays(int* arr, int arrSize) {
    int prefix[2] = {1, 0};
    int ans = 0;
    int oddCount = 0;
    for(int i = 0; i < arrSize; i++){
        oddCount ^= arr[i]&1;
        prefix[oddCount]++;
        ans = (ans+prefix[oddCount^1])%1000000007;
    }
    return ans%1000000007;
}
