int cmp(const void* a, const void* b){
    int* x = *(int**)a;
    int* y = *(int**)b;
    if(x[0] != y[0]) return x[0]-y[0];
    else return y[1]-x[1];
}

int numberOfPairs(int** points, int pointsSize, int* pointsColSize) {
    qsort(points, pointsSize, sizeof(int*), cmp);
    int ans = 0;
    for(int i = 0; i < pointsSize-1; i++){
        int xmin = points[i][0]-1, xmax = INT_MAX;
        int ymin = INT_MIN, ymax = points[i][1]+1;
        for(int j = i+1; j < pointsSize; j++){
            if(points[j][0] > xmin && points[j][0] < xmax && points[j][1] > ymin && points[j][1] < ymax){
                ans++;
                xmin = points[j][0];
                ymin = points[j][1];
            }
        }
    }
    return ans;
}
