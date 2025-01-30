bool IsWin(int* arr){
    return ((arr[0] != 0 && arr[0] == arr[1] && arr[1] == arr[2]) || (arr[3] != 0 && arr[3] == arr[4] && arr[4] == arr[5]) || (arr[6] != 0 && arr[6] == arr[7] && arr[7] == arr[8]) || (arr[0] != 0 && arr[0] == arr[3] && arr[3] == arr[6]) || (arr[1] != 0 && arr[1] == arr[4] && arr[4] == arr[7]) || (arr[2] != 0 && arr[2] == arr[5] && arr[5] == arr[8]) || (arr[0] != 0 && arr[0] == arr[4] && arr[4] == arr[8]) || (arr[2] != 0 && arr[2] == arr[4] && arr[4] == arr[6]));
}

char* tictactoe(int** moves, int movesSize, int* movesColSize) {
    int arr[9] = {0};
    for(int i = 0; i < movesSize; i++){
        int player = (i&1) == 0 ? 1 : 2;
        arr[moves[i][0]*3+moves[i][1]] = player;
        if(IsWin(arr)) return player == 1 ? "A" : "B";
    }
    return movesSize == 9 ? "Draw" : "Pending";
}
