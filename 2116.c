bool canBeValid(char* s, char* locked) {
    int len = strlen(s);
    if(len%2 == 1) return 0;
    int left = 0, right = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == '(' || locked[i] == '0') left++;
        else left--;
        if(left < 0) return 0;
    }
    for(int i = len-1; i >= 0; i--){
        if(s[i] == ')' || locked[i] == '0') right++;
        else right--;
        if(right < 0) return 0;
    }
    return 1;
}
