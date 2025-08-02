/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int getHeight(struct TreeNode* root){
    if(!root) return 0;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    return left > right ? left+1 : right+1;
}

void dfs(struct TreeNode* root, int depth, int cur, int* ans){
    if(!root) return;
    if(!root->left && !root->right){
        if(cur == depth) *ans += root->val;
    }
    dfs(root->left, depth, cur+1, ans);
    dfs(root->right, depth, cur+1, ans);
}

int deepestLeavesSum(struct TreeNode* root) {
    int ans = 0;
    int depth = getHeight(root);
    dfs(root, depth, 1, &ans);
    return ans;
}
