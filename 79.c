bool dfs(char** board, int boardSize, int boardColSize, char* word, int n, int i, int j){
    if(word[n] == '\0') return 1;
    if(i < 0 || i >= boardSize || j < 0 || j >= boardColSize || board[i][j] != word[n]) return 0;
    char temp = board[i][j];
    board[i][j] = '@';
    int res = dfs(board, boardSize, boardColSize, word, n+1, i+1, j) || dfs(board, boardSize, boardColSize, word, n+1, i-1, j) || dfs(board, boardSize, boardColSize, word, n+1, i, j+1) || dfs(board, boardSize, boardColSize, word, n+1, i, j-1);
    board[i][j] = temp;
    return res;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < (*boardColSize); j++){
            if(dfs(board, boardSize, (*boardColSize), word, 0, i, j)) return 1;
        }
    }
    return 0;
}
