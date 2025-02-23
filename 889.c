/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* constructFromPrePost(int* preorder, int preorderSize, int* postorder, int postorderSize) {
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if(preorderSize == 0) return NULL;
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;
    if(preorderSize == 1) return root;
    int leftSize = 0;
    while(postorder[leftSize] != preorder[1]){
        leftSize++;
    }
    leftSize++;
    root->left = constructFromPrePost(preorder+1, leftSize, postorder, leftSize);
    root->right = constructFromPrePost(preorder+1+leftSize, preorderSize-1-leftSize, postorder+leftSize, postorderSize-1-leftSize);
    return root;
}
