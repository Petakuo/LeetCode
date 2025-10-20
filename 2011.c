Sol1: 
int finalValueAfterOperations(char** operations, int operationsSize) {
    int ans = 0;
    for(int i = 0; i < operationsSize; i++){
        for(int j = 0; operations[i][j] != '\0'; j++){
            if(operations[i][j] == '+'){
                ans++;
                break;
            }
            else if(operations[i][j] == '-'){
                ans--;
                break;
            }
        }
    }
    return ans;
}

Sol2: 
int finalValueAfterOperations(char** operations, int operationsSize) {
    int ans = 0;
    for(int i = 0; i < operationsSize; i++){
        if(strcmp(operations[i], "X++") == 0 || strcmp(operations[i], "++X") == 0) ans++;
        else ans--;
    }
    return ans;
}
