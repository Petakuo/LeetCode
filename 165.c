int compareVersion(char* version1, char* version2) {
    int ptr1 = 0, ptr2 = 0;
    int len1 = strlen(version1), len2 = strlen(version2);
    while(ptr1 < len1 || ptr2 < len2){
        int v1 = 0, v2 = 0;
        if(ptr1 < len1){
            while(version1[ptr1] != '.' && version1[ptr1] != '\0'){
                v1 = v1*10+(version1[ptr1++]-'0');
            }
        }
        else v1 = 0;
        if(ptr2 < len2){
            while(version2[ptr2] != '.' && version2[ptr2] != '\0'){
                v2 = v2*10+(version2[ptr2++]-'0');
            }
        }
        else v2 = 0;
        if(v1 > v2) return 1;
        if(v2 > v1) return -1;
        ptr1++;
        ptr2++;
    }
    return 0;
}
