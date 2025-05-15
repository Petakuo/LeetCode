/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** getLongestSubsequence(char** words, int wordsSize, int* groups, int groupsSize, int* returnSize) {
    int start0 = 0, start1 = 0;
    while(start0 < groupsSize-1 && groups[start0] != 0){
        start0++;
    }
     while(start1 < groupsSize-1 && groups[start1] != 1){
        start1++;
    }
    int count0 = 0, count1 = 0;
    for(int i = start0+1; i < groupsSize;){
        while(i < groupsSize && groups[i] == groups[i-1]){
            i++;
        }
        count0++;
        i++;
    }
    for(int i = start1+1; i < groupsSize;){
        while(i < groupsSize && groups[i] == groups[i-1]){
            i++;
        }
        count1++;
        i++;
    }
    int start = count0 > count1 ? start0 : start1;
    int size = count0 > count1 ? count0 : count1;
    char** ans = (char**)malloc((size+1)*sizeof(char*));
    *returnSize = 0;
    ans[(*returnSize)++] = words[start];
    for(int i = start+1; i < wordsSize;){
        while(i < wordsSize && groups[i] == groups[i-1]){
            i++;
        }
        if(i < wordsSize) ans[(*returnSize)++] = words[i];
        i++;
    }
    return ans;
}
