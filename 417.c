/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(int** heights, int m, int n, bool** visited, int r, int c, int dir[4][2]){
    visited[r][c] = 1;
    for(int i = 0; i < 4; i++){
        int newr = r+dir[i][0];
        int newc = c+dir[i][1];
        if(newr >= 0 && newr < m && newc >= 0 && newc < n && !visited[newr][newc] && heights[newr][newc] >= heights[r][c]) dfs(heights, m, n, visited, newr, newc, dir);
    }
}

int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool** pac = (bool**)malloc(heightsSize*sizeof(bool*));
    bool** atl = (bool**)malloc(heightsSize*sizeof(bool*));
    for(int i = 0; i < heightsSize; i++){
        pac[i] = calloc(heightsColSize[0], sizeof(bool));
        atl[i] = calloc(heightsColSize[0], sizeof(bool));
    }
    for(int i = 0; i < heightsSize; i++){
        dfs(heights, heightsSize, heightsColSize[0], pac, i, 0, dir);
        dfs(heights, heightsSize, heightsColSize[0], atl, i, heightsColSize[0]-1, dir);
    }
    for(int i = 0; i < heightsColSize[0]; i++){
        dfs(heights, heightsSize, heightsColSize[0], pac, 0, i, dir);
        dfs(heights, heightsSize, heightsColSize[0], atl, heightsSize-1, i, dir);
    }
    int** ans = (int**)malloc(heightsSize*heightsColSize[0]*sizeof(int*));
    *returnColumnSizes = malloc(heightsSize*heightsColSize[0]*sizeof(int));
    *returnSize = 0;
    for(int i = 0; i < heightsSize; i++){
        for(int j = 0; j < heightsColSize[0]; j++){
            if(pac[i][j] && atl[i][j]){
                ans[(*returnSize)] = malloc(2*sizeof(int));
                ans[(*returnSize)][0] = i;
                ans[(*returnSize)][1] = j;
                (*returnColumnSizes)[(*returnSize)++] = 2;
            }
        }
    }
    for(int i = 0; i < heightsSize; i++){
        free(pac[i]);
        free(atl[i]);
    }
    free(pac);
    free(atl);
    return ans;
}
