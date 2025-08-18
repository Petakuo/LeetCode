bool backtracking(double* cards, int Size){
    if(Size == 1) return fabs(cards[0]-24) <= 0.000001;
    double* merge = (double*)calloc(Size-1, sizeof(double));
    for(int i = 0; i < Size; i++){
        for(int j = i+1; j < Size; j++){
            int mergeSize = 0;
            for(int k = 0; k < Size; k++){
                if(k != i && k != j) merge[mergeSize++] = cards[k];
            }
            merge[mergeSize++] = cards[i]+cards[j];
            if(backtracking(merge, mergeSize)) return 1;
            mergeSize--;
            merge[mergeSize++] = cards[i]-cards[j];
            if(backtracking(merge, mergeSize)) return 1;
            mergeSize--;
            merge[mergeSize++] = cards[j]-cards[i];
            if(backtracking(merge, mergeSize)) return 1;
            mergeSize--;
            merge[mergeSize++] = cards[i]*cards[j];
            if(backtracking(merge, mergeSize)) return 1;
            mergeSize--;
            merge[mergeSize++] = cards[i]/cards[j];
            if(backtracking(merge, mergeSize)) return 1;
            mergeSize--;
            merge[mergeSize++] = cards[j]/cards[i];
            if(backtracking(merge, mergeSize)) return 1;
            mergeSize--;
        }
    }
    free(merge);
    return 0;
}

bool judgePoint24(int* cards, int cardsSize) {
    double* dcards = (double*)calloc(cardsSize, sizeof(double));
    for(int i = 0; i < cardsSize; i++){
        dcards[i] = cards[i];
    }
    bool ans = backtracking(dcards, cardsSize);
    free(dcards);
    return ans;
}
