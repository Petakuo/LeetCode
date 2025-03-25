int cmpV(const void* a, const void* b){
    return (*(int**)a)[0]-(*(int**)b)[0];
}

int cmpH(const void* a, const void* b){
    return (*(int**)a)[1]-(*(int**)b)[1];
}

bool checkValidCuts(int n, int** rectangles, int rectanglesSize, int* rectanglesColSize) {
    qsort(rectangles, rectanglesSize, sizeof(int*), cmpV);
    bool canV = 0;
    int canCut = 0;
    int left = rectangles[0][0], right = rectangles[0][2];
    for(int i = 1; i < rectanglesSize; i++){
        if(rectangles[i][0] >= right){
            canCut++;
            left = rectangles[i][0];
            right = rectangles[i][2];
        }
        else if(rectangles[i][2] > right) right = rectangles[i][2];
    }
    if(canCut >= 2) canV = 1;
    qsort(rectangles, rectanglesSize, sizeof(int*), cmpH);
    bool canH = 0;
    canCut = 0;
    int low = rectangles[0][1], high = rectangles[0][3];
    for(int i = 1; i < rectanglesSize; i++){
        if(rectangles[i][1] >= high){
            canCut++;
            low = rectangles[i][1];
            high = rectangles[i][3];
        }
        else if(rectangles[i][3] > high) high = rectangles[i][3];
    }
    if(canCut >= 2) canH = 1;
    return canV || canH;
}
