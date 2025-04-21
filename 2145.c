int numberOfArrays(int* differences, int differencesSize, int lower, int upper) {
    int minPre = 0, maxPre = 0;
    int Pre = 0;
    for(int i = 0; i < differencesSize; i++){
        Pre += differences[i];
        if(Pre < minPre) minPre = Pre;
        if(Pre > maxPre) maxPre = Pre;
        if(maxPre-minPre > upper-lower) return 0;
    }
    int minStart = lower-minPre;
    int maxStart = upper-maxPre;
    return maxStart-minStart+1;
}
