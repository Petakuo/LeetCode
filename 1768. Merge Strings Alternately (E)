char * mergeAlternately(char * word1, char * word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    char* ans = (char*)malloc((len1+len2+1)*sizeof(char));
    ans[len1+len2] = '\0';
    int index = 0;
    while(index < len1 && index < len2){
        ans[index*2] = word1[index];
        ans[index*2+1] = word2[index];
        index++;
    }
    while(index < len1){
        ans[index+len2] = word1[index];
        index++;
    }
    while(index < len2){
        ans[index+len1] = word2[index];
        index++;
    }
    return ans;
}
