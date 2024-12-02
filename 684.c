/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int find(int* root, int n){
    if(root[n] != n) root[n] = find(root, root[n]);
    return root[n];
}

void unionset(int* root, int* height, int a, int b){
    int rootA = find(root, a);
    int rootB = find(root, b);
    if(rootA != rootB){
        if(height[rootA] < height[rootB]){
            root[rootA] = root[rootB];
        }
        else if(height[rootA] > height[rootB]){
            root[rootB] = root[rootA];
        }
        else {
            root[rootA] = root[rootB];
            height[rootB]++;
        }
    }
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    *returnSize = 2;
    int* ans = (int*)malloc(2*sizeof(int));
    int root[1001] = {0};
    int height[1001] = {1};
    for(int i = 0; i < 1001; i++){
        root[i] = i;
    }
    for(int i = 0; i < edgesSize; i++){
        int a = edges[i][0];
        int b = edges[i][1];
        if(find(root, a) == find(root, b)){
            ans[0] = a;
            ans[1] = b;
            return ans;
        }
        unionset(root, height, a, b);
    }
    return 0;
}
