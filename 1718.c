/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool backtracking(int n, int* arr, int index, int size, int currentSize, bool* used){
    if(currentSize == n) return 1;
    for(int i = n; i >= 1; i--){
        int put = i == 1 ? index : index+i;
        if(used[i] || put >= size || arr[index] != 0 || arr[put] != 0) continue;
        arr[index] = i;
        arr[put] = i;
        used[i] = 1;
        int nextIndex = index;
        while((nextIndex < size) && arr[nextIndex] != 0){
            nextIndex++;
        }
        if(backtracking(n, arr, nextIndex, size, currentSize+1, used)) return 1;
        arr[index] = 0;
        arr[put] = 0;
        used[i] = 0;
    }
    return 0;
}

int* constructDistancedSequence(int n, int* returnSize) {
    int size = 2*n-1;
    int* ans = (int*)calloc(size, sizeof(int));
    bool* used = (bool*)calloc(n+1, sizeof(bool));
    *returnSize = size;
    backtracking(n, ans, 0, size, 0, used);
    free(used);
    return ans;
}
