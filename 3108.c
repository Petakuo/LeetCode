/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct disjointSet{
    int* parent;
    int* cost;
};

int find(struct disjointSet* set, int i){
    if(set->parent[i] != i) set->parent[i] = find(set, set->parent[i]);
    return set->parent[i];
}

int* minimumCost(int n, int** edges, int edgesSize, int* edgesColSize, int** query, int querySize, int* queryColSize, int* returnSize) {
    struct disjointSet set;
    set.parent = (int*)malloc(n*sizeof(int));
    set.cost = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        set.parent[i] = i;
        set.cost[i] = INT_MAX;
    }
    for(int i = 0; i < edgesSize; i++){
        int uroot = find(&set, edges[i][0]);
        int vroot = find(&set, edges[i][1]);
        set.cost[uroot] &= edges[i][2];
        if(uroot != vroot){
            set.parent[vroot] = uroot;
            set.cost[uroot] &= set.cost[vroot];
        }
    }
    int* ans = (int*)malloc(querySize*sizeof(int));
    *returnSize = querySize;
    for(int i = 0; i < querySize; i++){
        if(query[i][0] == query[i][1]){
            ans[i] = 0;
            continue;
        }
        if(find(&set, query[i][0]) == find(&set, query[i][1])) ans[i] = set.cost[find(&set, query[i][0])];
        else ans[i] = -1;
    }
    free(set.parent);
    free(set.cost);
    return ans;
}
