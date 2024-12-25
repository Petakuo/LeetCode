/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int treeHeight(struct TreeNode* root){
    if(!root) return 0;
    int leftHeight = 1+treeHeight(root->left), rightHeight = 1+treeHeight(root->right);
    return leftHeight > rightHeight ? leftHeight : rightHeight;
}

int* largestValues(struct TreeNode* root, int* returnSize) {
    int height = treeHeight(root);
    if(height == 0){
        *returnSize = 0;
        return NULL;
    }
    int* ans = (int*)malloc(height*sizeof(int));
    *returnSize = height;
    struct TreeNode* queue[10001];
    int start = 0, end = 0, ansIndex = 0;
    queue[end++] = root;
    while(start < end){
        int max = queue[start]->val;
        int size = end-start;
        for(int i = 0; i < size; i++){
            max = max > queue[start]->val ? max : queue[start]->val;
            if(queue[start]->left) queue[end++] = queue[start]->left;
            if(queue[start]->right) queue[end++] = queue[start]->right;
            start++;
        }
        ans[ansIndex++] = max;
    }
    return ans;
}
