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
void tra(struct TreeNode* root, int* arr, int* returnSize){
    if(root){
        tra(root->left, arr, returnSize);
        arr[(*returnSize)] = root->val;
        (*returnSize)++;
        tra(root->right, arr, returnSize);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(101*sizeof(int));
    *returnSize = 0;
    tra(root, arr, returnSize);
    return arr;
}
