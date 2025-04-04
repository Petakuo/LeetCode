/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* dfs(struct TreeNode* root, int* depth){
    if(!root){
        *depth = 0;
        return root;
    }
    int ldepth = 0, rdepth = 0;
    struct TreeNode* left = dfs(root->left, &ldepth);
    struct TreeNode* right = dfs(root->right, &rdepth);
    if(ldepth > rdepth){
        *depth = ldepth+1;
        return left;
    }
    if(rdepth > ldepth){
        *depth = rdepth+1;
        return right;
    }
    else{
        *depth = ldepth+1;
        return root;
    }
}

struct TreeNode* lcaDeepestLeaves(struct TreeNode* root) {
    int depth = 0;
    return dfs(root, &depth);
}
