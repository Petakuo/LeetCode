/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSame(struct TreeNode* root1, struct TreeNode* root2){
    if(!root1 && !root2) return 1;
    if(!root1 || !root2) return 0;
    if(root1->val != root2->val) return 0;
    bool left = isSame(root1->left, root2->left);
    bool right = isSame(root1->right, root2->right);
    return left && right;
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if(!root) return 0;
    if(isSame(root, subRoot)) return 1;
    else return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
