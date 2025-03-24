int cmp(const void* a, const void* b){
    return (*(*(int**)a))-(*(*(int**)b));
}

int countDays(int days, int** meetings, int meetingsSize, int* meetingsColSize) {
    qsort(meetings, meetingsSize, sizeof(int*), cmp);
    int left = meetings[0][0], right = meetings[0][1];
    for(int i = 1; i < meetingsSize; i++){
        if(meetings[i][0] > right){
            days -= right-left+1;
            left = meetings[i][0];
            right = meetings[i][1];
            continue;
        }
        else if(meetings[i][1] > right) right = meetings[i][1];
    }
    days -= right-left+1;
    return days;
}
