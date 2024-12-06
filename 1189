int maxNumberOfBalloons(char* text) {
    int balloon[5] = {0};
    for(int i = 0; i < strlen(text); i++){
        if(text[i] == 'a') balloon[0]++;
        if(text[i] == 'b') balloon[1]++;
        if(text[i] == 'l') balloon[2]++;
        if(text[i] == 'n') balloon[3]++;
        if(text[i] == 'o') balloon[4]++;
    }
    balloon[2] /= 2;
    balloon[4] /= 2;
    int min = balloon[0];
    for(int i = 1; i < 5; i++){
        min = min < balloon[i] ? min : balloon[i];
    }
    return min;
}
