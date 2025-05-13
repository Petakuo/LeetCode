#define MOD 1000000007;

int lengthAfterTransformations(char* s, int t) {
    int freq[26] = {0};
    for(int i = 0; s[i] != '\0'; i++){
        freq[s[i]-'a']++;
    }
    for(int i = 0; i < t; i++){
        int ptr = 25-(i%26);
        if(freq[ptr] > 0){
            freq[(ptr+1)%26] = (freq[(ptr+1)%26]+freq[ptr])%MOD;
        }
    }
    int ans = 0;
    for(int i = 0; i < 26; i++){
        ans = (ans+freq[i])%MOD;
    }
    return ans;
}
