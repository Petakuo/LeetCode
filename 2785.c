bool Isvow(char s){
    if((s == 'A') || (s == 'E') || (s == 'I') || (s == 'O') || (s == 'U') || (s == 'a') || (s == 'e') || (s == 'i') || (s == 'o') || (s == 'u')) return 1;
    else return 0;
}

int compare(const void *a, const void *b){
    return *(char*)a-*(char*)b;
}

char* sortVowels(char* s) {
    int len = strlen(s);
    char* Vowels = (char*)malloc((len+1)*sizeof(char));
    Vowels[len] = '\0';
    int count = 0;
    for(int i = 0; i < len; i++){
        if(Isvow(s[i])){
            Vowels[count] = s[i];
            count++;
        }
    }
    Vowels[count] = '\0';
    qsort(Vowels, count, sizeof(char), compare);
    count = 0;
    for(int i = 0; i < len; i++){
        if(Isvow(s[i])){
            s[i] = Vowels[count];
            count++;
        }
    }
    free(Vowels);
    return s;
}
