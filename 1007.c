int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize) {
    int freq[7] = {0};
    int max = tops[0];
    for(int i = 0; i < topsSize; i++){
        freq[tops[i]]++;
        freq[bottoms[i]]++;
        max = freq[tops[i]] > freq[max] ? tops[i] : max;
        max = freq[bottoms[i]] > freq[max] ? bottoms[i] : max;
    }
    if(freq[max] < topsSize) return -1;
    int t = 0, b = 0, minus = 0;
    for(int i = 0; i < topsSize; i++){
        if(tops[i] != max && bottoms[i] != max) return -1;
        if(tops[i] == max && bottoms[i] == max) minus++;
        if(tops[i] == max) t++;
        if(bottoms[i] == max) b++;
    }
    return (t > b ? b : t)-minus;
}
