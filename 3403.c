char* answerString(char* word, int numFriends) {
    if(numFriends == 1) return word;
    int len = strlen(word);
    int need = len-(numFriends-1);
    char* ans = (char*)malloc((need+1)*sizeof(char));
    strncpy(ans, word, need);
    for(int i = 0; word[i] != '\0'; i++){
        if(strncmp(ans, &word[i], need) < 0) ans = strncpy(ans, &word[i], need);
    }
    ans[need] = '\0';
    return ans;
}
