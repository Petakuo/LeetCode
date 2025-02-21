/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



typedef struct {
    int node[10000];
    int size;
} FindElements;

void newTree(FindElements* obj, struct TreeNode* root, int val){
    obj->node[obj->size] = val;
    (obj->size)++;
    if(root->left) newTree(obj, root->left, 2*val+1);
    if(root->right) newTree(obj, root->right, 2*val+2);
    return;
}

FindElements* findElementsCreate(struct TreeNode* root) {
    if(!root) return NULL;
    FindElements* obj = (FindElements*)malloc(sizeof(FindElements));
    obj->size = 0;
    newTree(obj, root, 0);
    return obj;
}

bool findElementsFind(FindElements* obj, int target) {
    for(int i = 0; i < obj->size; i++){
        if(obj->node[i] == target) return 1;
    }
    return 0;
}

void findElementsFree(FindElements* obj) {
    free(obj);
}

/**
 * Your FindElements struct will be instantiated and called as such:
 * FindElements* obj = findElementsCreate(root);
 * bool param_1 = findElementsFind(obj, target);
 
 * findElementsFree(obj);
*/
