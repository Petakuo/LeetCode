char* gcdOfStrings(char* str1, char* str2) {
    int ptr = 0;
    while(str1[ptr] != '\0' && str2[ptr] != '\0'){
        if(str1[ptr] == str2[ptr]) ptr++;
        else return "";
    }
    if(str1[ptr] == '\0' && str2[ptr] == '\0'){
        return str1;
    }
    else if(str1[ptr] == '\0'){
        return gcdOfStrings(str1, str2+ptr);
    }
    else return gcdOfStrings(str2, str1+ptr);
}
