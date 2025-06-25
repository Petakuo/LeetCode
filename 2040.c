long long kthSmallestProduct(int* nums1, int nums1Size, int* nums2, int nums2Size, long long k) {
    int neg1 = 0, neg2 = 0;
    while(neg1 < nums1Size && nums1[neg1] < 0){
        neg1++;
    }
    while(neg2 < nums2Size && nums2[neg2] < 0){
        neg2++;
    }
    long long left = LLONG_MIN, right = LLONG_MAX;
    while(left <= right){
        long long guess = left/2+right/2;
        long long count = 0;
        int i = 0, j = neg2-1;
        while(i < neg1 && j >= 0){
            if((long long)nums1[i]*nums2[j] > guess) i++;
            else{
                j--;
                count += neg1-i;
            }
        }
        i = neg1, j = nums2Size-1;
        while(i < nums1Size && j >= neg2){
            if((long long)nums1[i]*nums2[j] > guess) j--;
            else{
                i++;
                count += j-neg2+1;
            }
        }
        i = 0, j = neg2;
        while(i < neg1 && j < nums2Size){
            if((long long)nums1[i]*nums2[j] > guess) j++;
            else{
                i++;
                count += nums2Size-j;
            }
        }
        i = neg1, j = 0;
        while(i < nums1Size && j < neg2){
            if((long long)nums1[i]*nums2[j] > guess) i++;
            else{
                j++;
                count += nums1Size-i;
            }
        }
        if(count < k) left = guess+1;
        else right = guess-1;
    }
    return left;
}
