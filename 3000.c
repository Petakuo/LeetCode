int areaOfMaxDiagonal(int** dimensions, int dimensionsSize, int* dimensionsColSize) {
    int maxDiag = 0, maxArea = 0;
    for(int i = 0; i < dimensionsSize; i++){
        int curDiag = dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1];
        int curArea = dimensions[i][0]*dimensions[i][1];
        if(curDiag > maxDiag || (curDiag == maxDiag && curArea > maxArea)){
            maxDiag = curDiag;
            maxArea = curArea;
        }
    }
    return maxArea;
}
