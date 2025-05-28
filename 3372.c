/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct Node{
    int val;
    struct Node* next;
}Node;

int dfs(Node* tree[], int u, int parent, int path){
    if(path < 0) return 0;
    int count = 1;
    for(Node* cur = tree[u];cur; cur = cur->next){
        if(cur->val != parent) count += dfs(tree, cur->val, u, path-1);
    }
    return count;
}

void buildTree(Node* tree[], int** edge, int edgeSize){
    for(int i = 0; i < edgeSize; i++){
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

int* maxTargetNodes(int** edges1, int edges1Size, int* edges1ColSize, int** edges2, int edges2Size, int* edges2ColSize, int k, int* returnSize) {
    int* ans = (int*)malloc((edges1Size+1)*sizeof(int));
    Node* tree1[1001] = {0};
    Node* tree2[1001] = {0};
    buildTree(tree1, edges1, edges1Size);
    buildTree(tree2, edges2, edges2Size);
    int max = 0;
    for(int i = 0; i < edges2Size+1; i++){
        int now = dfs(tree2, i, -1, k-1);
        max = max > now ? max : now;
    }
    for(int i = 0; i < edges1Size+1; i++){
        ans[i] = dfs(tree1, i, -1, k)+max;
    }
    *returnSize = edges1Size+1;
    return ans;
}
