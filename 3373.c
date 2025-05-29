/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct Node{
    int val;
    struct Node* next;
}Node;

void dfs(Node* tree[], int u, int parent, int path, int* parity){
    parity[u] = path%2;
    for(Node* cur = tree[u]; cur; cur = cur->next){
        if(cur->val != parent) dfs(tree, cur->val, u, path+1, parity);
    }
}

void buildTree(Node* tree[], int** edge, int edgesSize){
    for(int i = 0; i < edgesSize; i++){
        int u = edge[i][0], v = edge[i][1];
        Node* node1 = (Node*)malloc(sizeof(Node));
        node1->val = u;
        node1->next = tree[v];
        tree[v] = node1;
        Node* node2 = (Node*)malloc(sizeof(Node));
        node2->val = v;
        node2->next = tree[u];
        tree[u] = node2;
    }
}

int* maxTargetNodes(int** edges1, int edges1Size, int* edges1ColSize, int** edges2, int edges2Size, int* edges2ColSize, int* returnSize) {
    int* ans = (int*)malloc((edges1Size+1)*sizeof(int));
    Node** tree1 = (Node**)calloc((edges1Size+1), sizeof(Node*));
    Node** tree2 = (Node**)calloc((edges2Size+1), sizeof(Node*));
    buildTree(tree1, edges1, edges1Size);
    buildTree(tree2, edges2, edges2Size);
    int* parity1 = malloc((edges1Size+1)*sizeof(int));
    int* parity2 = malloc((edges2Size+1)*sizeof(int));
    dfs(tree1, 0, -1, 0, parity1);
    dfs(tree2, 0, -1, 0, parity2);
    int countT1[2] = {0, 0};
    for (int i = 0; i < edges1Size+1; i++) countT1[parity1[i]]++;
    int countT2[2] = {0, 0};
    for (int i = 0; i < edges2Size+1; i++) countT2[parity2[i]]++;
    int maxT2 = countT2[0] > countT2[1] ? countT2[0] : countT2[1];
    for (int i = 0; i < edges1Size+1; i++) {
        ans[i] = countT1[parity1[i]]+maxT2;
    }
    *returnSize = edges1Size+1;
    return ans;
}
