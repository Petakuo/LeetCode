int findChampion(int n, int** edges, int edgesSize, int* edgesColSize) {
    if(n == 1) return 0;
    int* freq = (int*)calloc(n, sizeof(int));
    for(int i = 0; i < edgesSize; i++){
        freq[edges[i][1]]++;
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(freq[i] == 0) count++;
    }
    if(count > 1) return -1;
    for(int i =0; i < n; i++){
        if(freq[i] == 0) return i;
    }
    free(freq);
    return 0;
}
