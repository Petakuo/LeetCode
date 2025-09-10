int minimumTeachings(int n, int** languages, int languagesSize, int* languagesColSize, int** friendships, int friendshipsSize, int* friendshipsColSize) {
    bool know[501][501] = {0};
    for(int i = 0; i < languagesSize; i++){
        for(int j = 0; j < languagesColSize[i]; j++){
            know[i+1][languages[i][j]] = 1;
        }
    }
    bool need[501] = {0};
    for(int i = 0; i < friendshipsSize; i++){
        int u = friendships[i][0];
        int v = friendships[i][1];
        bool same = 0;
        for(int j = 1; j <= n; j++){
            if(know[u][j] && know[v][j]){
                same = 1;
                break;
            }
        }
        if(!same){
            need[u] = 1;
            need[v] = 1;
        }
    }
    int ans = 500;
    for(int i = 1; i <= n; i++){
        int teach = 0;
        for(int j = 1; j <= languagesSize; j++){
            if(need[j] && !know[j][i]) teach++;
        }
        ans = ans < teach ? ans : teach;
    }
    return ans;
}
