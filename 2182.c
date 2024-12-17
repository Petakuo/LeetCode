char* repeatLimitedString(char* s, int repeatLimit) {
    int len = strlen(s);
    int table[26] = {0};
    for(int i = 0; i < len; i++){
        table[s[i]-'a']++;
    }
    char* temp = s;
    int index = 0;
    for(int i = 25; i >= 0; i--){
        while(table[i]){
            temp[index] = i+'a';
            table[i]--;
            index++;
        }
    }
    int count = 1, swap = 0;
    for(int i = 1; i < len; i++){
        if(temp[i] == temp[i-1]) count++;
        else count = 1;
        if(count > repeatLimit){
            while(swap < len && temp[swap] >= temp[i]){
                swap++;
            }
            char a = temp[i];
            temp[i] = temp[swap];
            temp[swap] = a;
        }
    }
    return s;
}
