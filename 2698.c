bool canPartition(char* str, int target, int index, int currentSum){
    if(index == strlen(str)) return currentSum == target;
    int num = 0;
    for(int i = index; i < strlen(str); i++){
        num = num*10+(str[i]-'0');
        if(currentSum+num > target) break;
        if(canPartition(str, target, i+1, currentSum+num)) return 1;
    }
    return 0;
}

int punishmentNumber(int n) {
    int ans = 0;
    char str[8];
    for(int i = 0 ; i <= n; i++){
        sprintf(str, "%d", i*i);
        if(canPartition(str, i, 0, 0)) ans += i*i;
    }
    return ans;
}
