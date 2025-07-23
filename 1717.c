int countN(char* s, char a, char b){
    char* stack = (char*)malloc((strlen(s)+1)*sizeof(char));
    int top = -1, count = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(top > -1 && stack[top] == a && s[i] == b){
            count++;
            top--;
        }
        else stack[++top] = s[i];
    }
    memcpy(s, stack, top+1);
    s[top+1] = '\0';
    free(stack);
    return count;
}


int maximumGain(char* s, int x, int y) {
    int ab = 0, ba = 0;
    if(x > y){
        ab = countN(s, 'a', 'b');
        ba = countN(s, 'b', 'a');
    }
    else{
        ba = countN(s, 'b', 'a');
        ab = countN(s, 'a', 'b');
    }
    return ab*x+ba*y;
}
