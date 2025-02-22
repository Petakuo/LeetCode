/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* newNode(int v){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = v;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* recoverFromPreorder(char* traversal) {
    struct TreeNode* stack[1000];
    int top = -1, i = 0;
    while(traversal[i] != '\0'){
        int depth = 0;
        while(traversal[i] == '-'){
            depth++;
            i++;
        }
        int v = 0;
        while(traversal[i] != '-' && traversal[i] != '\0'){
            v = v*10+(traversal[i]-'0');
            i++;
        }
        struct TreeNode* node = newNode(v);
        while(top >= depth){
            top--;
        }
        if(top >= 0){
            if(stack[top]->left == NULL) stack[top]->left = node;
            else stack[top]->right = node;
        }
        top++;
        stack[top] = node;
    }
    return stack[0];
}
