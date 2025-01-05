char* shiftingLetters(char* s, int** shifts, int shiftsSize, int* shiftsColSize) {
    int len = strlen(s);
    int* shiftArr = (int*)calloc((len+1), sizeof(int));
    for(int i = 0; i < shiftsSize; i++){
        int start = shifts[i][0];
        int end = shifts[i][1]+1;
        int move = shifts[i][2] == 1 ? 1 : -1;
        shiftArr[start] += move;
        shiftArr[end] -= move;
    }
    for(int i = 1; i < len+1; i++){
        shiftArr[i] += shiftArr[i-1];
    }
    for(int i = 0; i < len; i++){
        s[i] = 'a'+(s[i]-'a'+(((shiftArr[i]%26)+26)%26))%26;
    }
    free(shiftArr);
    return s;
}
