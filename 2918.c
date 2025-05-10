long long minSum(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    long long zero1 = 0, zero2 = 0, sum1 = 0, sum2 = 0;
    for(int i = 0; i < nums1Size; i++){
        if(nums1[i] == 0) zero1++;
        sum1 += nums1[i];
    }
    for(int i = 0; i < nums2Size; i++){
        if(nums2[i] == 0) zero2++;
        sum2 += nums2[i];
    }
    if(zero1 == 0){
        if(sum1 < sum2+zero2) return -1;
    }
    if(zero2 == 0){
        if(sum2 < sum1+zero1) return -1;
    }
    return sum1+zero1 > sum2+zero2 ? sum1+zero1 : sum2+zero2;
}
