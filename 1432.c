int maxDiff(int num) {
    int temp = num, len = 0;
    while(temp){
        temp /= 10;
        len++;
    }
    char* max = (char*)malloc((len+1)*sizeof(char));
    max[len] = '\0';
    char* min = (char*)malloc((len+1)*sizeof(char));
    min[len] = '\0';
    temp = num;
    for(int i = 0; i < len; i++){
        max[i] = '0'+temp%10;
        min[i] = '0'+temp%10;
        temp /= 10;
    }
    char s = min[len-1];
    if(s == '1') {
        for(int i = len-1; i >= 0; i--){
            if(min[i] != s && min[i] != '0'){
                s = min[i];
                break;
            }
        }
        if(s != '1' && s != '0'){
            for(int i = 0; i < len; i++){
                min[i] = (min[i] == s) ? '0' : min[i];
            }
        }
    }
    else{
        for(int i = 0; i < len; i++){
            min[i] = (min[i] == s) ? '1' : min[i];
        }
    }
    for(int i = len-1; i >= 0; i--){
        if(max[i] != '9'){
            s = max[i];
            break;
        }
    }
    if(s != '9'){
        for(int i = 0; i < len; i++){
            max[i] = (max[i] == s) ? '9' : max[i];
        }
    }
    int maxNum = 0, minNum = 0;
    for(int i = len-1; i >= 0; i--){
        maxNum = maxNum*10+(max[i]-'0');
        minNum = minNum*10+(min[i]-'0');
    }
    if(minNum == 0){
        for(int i = len-1; i >= 0; i--){
            minNum = minNum*10+1;
        }
    }
    free(max);
    free(min);
    return maxNum-minNum;
}
