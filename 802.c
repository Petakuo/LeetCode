/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool dfs(int** graph, int* graphColSize, int* isSafe, int index){
    if(isSafe[index] > 0) return isSafe[index] == 2;
    isSafe[index] = 1;
    for(int i = 0; i < graphColSize[index]; i++){
        int connect = graph[index][i];
        if(!dfs(graph, graphColSize, isSafe, connect)) return 0;
    }
    isSafe[index] = 2;
    return 1;
}

int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize) {
    *returnSize = 0;
    int* isSafe = (int*)calloc(graphSize, sizeof(int));
    int* ans = (int*)calloc(graphSize, sizeof(int));
    for(int i = 0; i < graphSize; i++){
        if(dfs(graph, graphColSize, isSafe, i)){
            ans[(*returnSize)] = i;
            (*returnSize)++;
        }
    }
    free(isSafe);
    return ans;
}
