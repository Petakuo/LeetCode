/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(!root){
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int** ans = (int**)malloc(2000*sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(2000*sizeof(int));
    struct TreeNode* queue[2000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(front < rear){
        int levelSize = rear-front;
        ans[(*returnSize)] = (int*)malloc(levelSize*sizeof(int));
        (*returnColumnSizes)[(*returnSize)] = levelSize;
        for(int i = 0; i < levelSize; i++){
            struct TreeNode* node = queue[front++];
            ans[(*returnSize)][i] = node->val;
            if(node->left) queue[rear++] = node->left;
            if(node->right) queue[rear++] = node->right;
        }
        (*returnSize)++;
    }
    return ans;
}
