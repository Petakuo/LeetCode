int cmp(const void* a, const void* b){
    int* x = *(int**)a;
    int* y = *(int**)b;
    if(x[0] != y[0]) return x[0]-y[0];
    else return y[1]-x[1];
}

int numberOfPairs(int** points, int pointsSize, int* pointsColSize) {
    qsort(points, pointsSize, sizeof(int*), cmp);
    bool midPoint = 0;
    int ans = 0;
    for(int i = 0; i < pointsSize-1; i++){
        for(int j = i+1; j < pointsSize; j++){
            if(points[i][1] >= points[j][1]){
                for(int k = i+1; k < j; k++){
                    if((points[k][1] <= points[i][1]) && (points[k][1] >= points[j][1])){
                        midPoint = 1;
                        break;
                    }
                }
                if(midPoint){
                    midPoint = 0;
                    continue;
                }
                else ans++;
            }
        }
    }
    return ans;
}
