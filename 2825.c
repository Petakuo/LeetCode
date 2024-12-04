bool canMakeSubsequence(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int ptr1 = 0, ptr2 = 0;
    while(ptr1 < len1 && ptr2 < len2){
        if((str2[ptr2]-str1[ptr1] == 0) || (str2[ptr2]-str1[ptr1] == 1) || (str2[ptr2]-str1[ptr1] == -25)){
            ptr1++;
            ptr2++;
        }
        else ptr1++;
    }
    return ptr2 == len2;
}
