int maxCandies(int* status, int statusSize, int* candies, int candiesSize, int** keys, int keysSize, int* keysColSize, int** containedBoxes, int containedBoxesSize, int* containedBoxesColSize, int* initialBoxes, int initialBoxesSize) {
    bool hasBox[1001] = {0};
    bool canOpen[1001] = {0};
    bool opened[1001] = {0};
    int queue[5000] = {0};
    int ans = 0, front = 0, rear = 0;
    for(int i = 0; i < initialBoxesSize; i++){
        queue[rear++] = initialBoxes[i];
        hasBox[initialBoxes[i]] = 1;
    }
    while(front < rear){
        for(int i = front; i < rear; i++){
            int box = queue[i];
            if(opened[box]) continue;
            if(status[box] == 0 && !canOpen[box]) continue;
            ans += candies[box];
            opened[box] = 1;
            for(int j = 0; j < keysColSize[box]; j++){
                int k = keys[box][j];
                if(!canOpen[k]){
                    canOpen[k] = 1;
                    if(hasBox[k] && !opened[k]) queue[rear++] = k;  
                }
            }
            for(int j = 0; j < containedBoxesColSize[box]; j++){
                int k = containedBoxes[box][j];
                if(!hasBox[k]){
                    hasBox[k] = 1;
                    queue[rear++] = k;
                }
            }
        }
        front++;
    }
    return ans;
}
