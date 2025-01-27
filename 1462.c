/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* checkIfPrerequisite(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    bool* ans = (bool*)calloc(queriesSize, sizeof(bool));
    bool** graph = (bool**)malloc(numCourses*sizeof(bool*));
    for(int i = 0; i < numCourses; i++){
        graph[i] = (bool*)calloc(numCourses, sizeof(bool));
    }
    for(int i = 0; i < prerequisitesSize; i++){
        graph[prerequisites[i][0]][prerequisites[i][1]] = 1;
    }
    for(int k = 0; k < numCourses; k++){
        for(int i = 0; i < numCourses; i++){
            for(int j = 0; j < numCourses; j++){
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
    for(int i = 0; i < queriesSize; i++){
        ans[i] = graph[queries[i][0]][queries[i][1]];
    }
    for(int i = 0; i < numCourses; i++){
        free(graph[i]);
    }
    free(graph);
    return ans;
}
