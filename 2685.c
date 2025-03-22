int find(int* arr, int i){
    if(arr[i] != i) arr[i] = find(arr, arr[i]);
    return arr[i];
}

void Union(int* arr, int i, int j){
    arr[find(arr, j)] = find(arr, i);
}

int countCompleteComponents(int n, int** edges, int edgesSize, int* edgesColSize) {
    int* arr = (int*)malloc(n*sizeof(int));
    int* node = (int*)malloc(n*sizeof(int));
    int* edge = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        arr[i] = i;
        node[i] = 1;
        edge[i] = 0;
    }
    for(int i = 0; i < edgesSize; i++){
        int root1 = find(arr, edges[i][0]);
        int root2 = find(arr, edges[i][1]);
        if(root1 != root2){
            Union(arr, root1, root2);
            node[root1] += node[root2];
            edge[root1] += edge[root2];
        }
        edge[root1]++;
    }
    int  ans = 0;
    bool* visit = (bool*)calloc(n, sizeof(bool));
    for(int i = 0; i < n; i++){
        int root = find(arr, i);
        if(visit[root] == 0){
            visit[root] = 1;
            if(edge[root] == node[root]*(node[root]-1)/2) ans++;
        }
    }
    free(arr);
    free(node);
    free(edge);
    free(visit);
    return ans;
}
