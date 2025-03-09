int numberOfAlternatingGroups(int* colors, int colorsSize, int k) {
    int ans = 0, count = 1;
    for(int i = 0; i < colorsSize+k-2; i++){
        if(colors[(i+1)%colorsSize] == colors[i%colorsSize]) count = 1;
        else count++;
        if(count >= k) ans++;
    }
    return ans;
}
