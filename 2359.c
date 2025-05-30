void dfs(int* edges, int* dist, int node, int d){
    while(node != -1 && dist[node] == -1){
        dist[node] = d++;
        node = edges[node];
    }
}

int closestMeetingNode(int* edges, int edgesSize, int node1, int node2) {
    int dist1[edgesSize], dist2[edgesSize];
    for(int i = 0; i < edgesSize; i++){
        dist1[i] = -1;
        dist2[i] = -1;
    }
    dfs(edges, dist1, node1, 0);
    dfs(edges, dist2, node2, 0);
    int nodeIdx = -1, maxDist = INT_MAX;
    for(int i = 0; i < edgesSize; i++){
        if(dist1[i] != -1 && dist2[i] != -1){
            int max = dist1[i] > dist2[i] ? dist1[i] : dist2[i];
            if(max < maxDist || (max == maxDist && i < nodeIdx)){
                maxDist = max;
                nodeIdx = i;
            }
        }
    }
    return nodeIdx;
}
