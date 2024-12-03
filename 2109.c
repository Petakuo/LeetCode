char* addSpaces(char* s, int* spaces, int spacesSize) {
    int len = strlen(s);
    char* ans = (char*)malloc((len+spacesSize+1)*sizeof(char));
    ans[len+spacesSize] = '\0';
    int sIndex = 0, spaceIndex = 0;
    for(int i = 0; i < len+spacesSize; i++){
        if((spaceIndex < spacesSize) && i == spaces[spaceIndex]+spaceIndex){
            ans[i] = ' ';
            spaceIndex++;
        }
        else{
            ans[i] = s[sIndex];
            sIndex++;
        }
    } 
    return ans;
}
