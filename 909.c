void getRealCoor(int Size, int n, int* row, int* col){
    int r = (n-1)/Size;
    int c = (n-1)%Size;
    if(r%2 == 1) c = Size-1-c;
    *row = Size-1-r;
    *col = c;
}

typedef struct{
    int num;
    int move;
}Node;

int snakesAndLadders(int** board, int boardSize, int* boardColSize) {
    bool visit[4001] = {0};
    Node queue[4000];
    int front = 0, rear = 0;
    queue[rear++] = (Node){1, 0};
    visit[0] = 1;
    while(front < rear){
        Node cur = queue[front++];
        for(int i = 1; i <= 6; i++){
            int next = cur.num+i;
            if(next > boardSize*boardSize) break;
            int r, c;
            getRealCoor(boardSize, next, &r, &c);
            if(board[r][c] != -1){
                next = board[r][c];
            }
            if(next == boardSize*boardSize) return cur.move+1;
            if(!visit[next]){
                visit[next] = 1;
                queue[rear++] = (Node){next, cur.move+1};
            }
        }
    }
    return -1;
}
