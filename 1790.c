bool areAlmostEqual(char* s1, char* s2) {
    int len = strlen(s1);
    int diff = 0, d11 = 0, d12 = 0, d21 = 0, d22 = 0;
    for(int i = 0; i < len; i++){
        if(s1[i] != s2[i]){
            diff++;
            if(diff == 1){
                d11 = s1[i];
                d21 = s2[i];
            }
            if(diff == 2){
                d12 = s1[i];
                d22 = s2[i];
            }
        }
        if(diff > 2) return 0;
    }
    return (d11 == d22) && (d12 == d21);
}
