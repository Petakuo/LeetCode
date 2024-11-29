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
void tra(struct TreeNode* root, int* ans, int* returnSize){
    if(!root) return;
    tra(root->left, ans, returnSize);
    tra(root->right, ans, returnSize);
    ans[(*returnSize)] = root->val;
    (*returnSize)++;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = (int*)malloc(101*sizeof(int));
    *returnSize = 0;
    tra(root, ans, returnSize);
    return ans;
}
