/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* rootL, struct TreeNode* rootR, int level){
    if(!rootL || !rootR) return;
    if(level%2 == 0){
        int temp = rootL->val;
        rootL->val = rootR->val;
        rootR->val = temp;
    }
    dfs(rootL->left, rootR->right, level+1);
    dfs(rootL->right, rootR->left, level+1);
}

struct TreeNode* reverseOddLevels(struct TreeNode* root) {
    if(!root) return NULL;
    int level = 0;
    dfs(root->left, root->right, level);
    return root;
}
