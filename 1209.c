typedef struct{
    int count;
    char c;
} stackElement;

char* removeDuplicates(char* s, int k) {
    int len = strlen(s);
    stackElement stack[len];
    int top = -1;
    for(int i = 0; i < len; i++){
        if(top >= 0 && stack[top].c == s[i]){
            stack[top].count++;
            if(stack[top].count == k) top--;
        }
        else{
            top++;
            stack[top].c = s[i];
            stack[top].count = 1;
        }
    }
    char* ans = (char*)malloc((len+1)*sizeof(char));
    int idx = 0;
    for(int i = 0; i <= top; i++){
        for(int j = 0; j < stack[i].count; j++){
            ans[idx++] = stack[i].c;
        }
    }
    ans[idx] = '\0';
    return ans;
}
