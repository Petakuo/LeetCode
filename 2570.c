/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** mergeArrays(int** nums1, int nums1Size, int* nums1ColSize, int** nums2, int nums2Size, int* nums2ColSize, int* returnSize, int** returnColumnSizes) {
    int** ans = (int**)malloc((nums1Size+nums2Size)*sizeof(int*));
    for(int i = 0; i < nums1Size+nums2Size; i++){
        ans[i] = (int*)malloc(2*sizeof(int));
    }
    int i = 0, j = 0, index = 0;
    while((i != nums1Size) && (j != nums2Size)){
        if(nums1[i][0] > nums2[j][0]){
            ans[index][0] = nums2[j][0];
            ans[index][1] = nums2[j][1];
            j++;
            index++;
        }
        else if(nums1[i][0] < nums2[j][0]){
            ans[index][0] = nums1[i][0];
            ans[index][1] = nums1[i][1];
            i++;
            index++;
        }
        else{
            ans[index][0] = nums1[i][0];
            ans[index][1] = nums1[i][1]+nums2[j][1];
            i++;
            j++;
            index++;
        }
    }
    while(i < nums1Size){
        ans[index][0] = nums1[i][0];
        ans[index][1] = nums1[i][1];
        i++;
        index++;
    }
    while(j < nums2Size){
        ans[index][0] = nums2[j][0];
        ans[index][1] = nums2[j][1];
        j++;
        index++;
    }
    *returnSize = index;
    *returnColumnSizes = (int*)malloc((index)*sizeof(int));
    for(int i = 0; i < index; i++){
        (*returnColumnSizes)[i] = 2;
    }
    return ans;
}
