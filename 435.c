int cmp(const void* a, const void* b){
    return *(*(int**)a)-*(*(int**)b);
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int right = intervals[0][1], count = 0;
    for(int i = 1; i < intervalsSize; i++){
        if(right > intervals[i][0]){
            count++;
            right = right > intervals[i][1] ? intervals[i][1] : right;
        }
        else right = intervals[i][1];
    }
    return count;
}
