/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode* root, int* ans){
    if(!root) return 0;
    int left = dfs(root->left, ans);
    int right = dfs(root->right, ans);
    int count = left+right+1; 
    int sum = root->val;
    sum += root->left ? root->left->val : 0;
    sum += root->right ? root->right->val : 0;
    if((sum/count) == root->val) (*ans)++;
    root->val = sum;
    return count;
}

int averageOfSubtree(struct TreeNode* root) {
    int ans = 0;
    dfs(root, &ans);
    return ans;
}
