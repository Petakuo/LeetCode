/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minOperations(char* boxes, int* returnSize) {
    int len = strlen(boxes);
    *returnSize = len;
    int* ans = (int*)malloc(len*sizeof(int));
    int leftballs = 0, leftmoves = 0;
    for(int i = 0; i < len; i++){
        ans[i] = leftmoves;
        if(boxes[i] == '1') leftballs++;
        leftmoves += leftballs;
    }
    int rightballs = 0, rightmoves = 0;
    for(int i = len-1; i >= 0; i--){
        ans[i] += rightmoves;
        if(boxes[i] == '1') rightballs++;
        rightmoves += rightballs;
    }
    return ans;
}
