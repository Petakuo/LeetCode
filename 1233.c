/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void* a, const void* b){
    return strcmp(*(char**)a, *(char**)b);
}

char** removeSubfolders(char** folder, int folderSize, int* returnSize) {
    qsort(folder, folderSize, sizeof(char*), cmp);
    char** ans = (char**)malloc(folderSize*sizeof(char*));
    int idx = 0;
    ans[idx++] = folder[0];
    for(int i = 1; i < folderSize; i++){
        int len = strlen(ans[idx-1]);
        if(strncmp(ans[idx-1], folder[i], len) != 0 || folder[i][len] != '/') ans[idx++] = folder[i];
    }
    *returnSize = idx;
    return ans;
}
