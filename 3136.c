bool isValid(char* word) {
    if(strlen(word) < 3) return 0;
    int vowel = 0, consonant = 0;
    for(int i = 0; word[i] != '\0'; i++){
        if(isalpha(word[i])){
            char a = tolower(word[i]);
            if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') vowel = 1;
            else consonant = 1;
        }
        else if(!isdigit(word[i])) return 0;
    }
    return vowel && consonant;
}
