Sol1: 
int minimumRecolors(char* blocks, int k) {
    int ans = 0;
    for(int i = 0; i < strlen(blocks); i++){
        if(blocks[i] == 'B')
            ans++;
        else
            ans = 0;
    }
    if(ans == k)
        return 0;
    else{
        ans = 0;
        for(int j = 0; j <= strlen(blocks)-k; j++){
            int temp = 0;
            for(int l = 0; l < k; l++){
                if(blocks[j+l] == 'B')
                    temp++;
                    if(temp > ans)
                        ans = temp;
            }
        }
    }
    return k-ans;
}

Sol2: 
int minimumRecolors(char* blocks, int k) {
    int len = strlen(blocks);
    int count = 0, left = 0, right = k-1;
    for(int i = left; i <= right; i++){
        if(blocks[i] == 'W') count++;
    }
    int ans = count;
    while(right < len-1){
        right++;
        if(blocks[right] == 'W') count++;
        if(blocks[left] == 'W') count--;
        left++;
        ans = count < ans ? count : ans;
    }
    return ans;
}
