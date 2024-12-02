int isPrefixOfWord(char* sentence, char* searchWord) {
    int senlen = strlen(sentence), searlen = strlen(searchWord);
    int index = 1, same = 0, pre = 1;
    for(int i = 0; i < senlen; i++){
        if(sentence[i] == ' '){
            index++;
            pre = 1;
            same = 0;
        }
        else if(pre == 1 && sentence[i] == searchWord[same]){
            same++;
            if(same == searlen) return index;
        }
        else{
            same = 0;
            pre = 0;
        }
    }
    return -1;
}
