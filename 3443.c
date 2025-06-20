int maxDistance(char* s, int k) {
    int len = strlen(s);
    int ans = 0;
    int N = 0, S = 0, W = 0, E = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == 'N') N++;
        if(s[i] == 'S') S++;
        if(s[i] == 'W') W++;
        if(s[i] == 'E') E++;
        int NE = N+E-S-W+2*fmin(k, S+W);
        int NW = N+W-S-E+2*fmin(k, S+E);
        int SE = S+E-N-W+2*fmin(k, N+W);
        int SW = S+W-N-E+2*fmin(k, N+E);
        if(NE > ans) ans = NE;
        if(NW > ans) ans = NW;
        if(SE > ans) ans = SE;
        if(SW > ans) ans = SW;
    }
    return ans;
}
