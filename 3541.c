int maxFreqSum(char* s) {
    int freq[26] = {0};
    for(int i = 0; s[i] != '\0'; i++){
        freq[s[i]-'a']++;
    }
    int maxV = 0, maxC = 0;
    for(int i = 0; i < 26; i++){
        if(i == 'a'-'a' || i == 'e'-'a' || i == 'i'-'a' || i == 'o'-'a' || i == 'u'-'a') maxV = maxV > freq[i] ? maxV : freq[i];
        else maxC = maxC > freq[i] ? maxC : freq[i];
    }
    return maxV+maxC;
}
