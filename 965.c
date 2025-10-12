/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool dfs(struct TreeNode* root, int val){
    if(!root) return 1;
    return dfs(root->left, val)&&dfs(root->right, val)&&(root->val == val);
}

bool isUnivalTree(struct TreeNode* root) {
    int val = root->val;
    return dfs(root, val);
}
