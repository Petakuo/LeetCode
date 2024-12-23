/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int cmp(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int minimumOperations(struct TreeNode* root) {
    int count = 0;
    struct TreeNode* queue[100001];
    int index[100001] = {-1};
    int start = 0, end = 0;
    queue[end++] = root;
    while(start < end){
        int size = end-start;
        int level[size];
        int sortLevel[size];
        for(int i = 0 ; i < size; i++){
            level[i] = queue[start]->val;
            sortLevel[i] = queue[start]->val;
            index[queue[start]->val] = i;
            if(queue[start]->left){
                queue[end] = queue[start]->left;
                end++;
            }
            if(queue[start]->right){
                queue[end] = queue[start]->right;
                end++;
            }
            start++;
        }
        qsort(sortLevel, size, sizeof(int), cmp);
        for(int i = 0; i < size; i++){
            if(level[i] != sortLevel[i]){
                count++;
                int swapTarget = index[sortLevel[i]];
                swap(&level[i], &level[swapTarget]);
                index[level[i]] = i;
                index[level[swapTarget]] = swapTarget;
            }
        }
    }
    return count;
}
