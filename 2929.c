long long C(int a, int b){
    if(a <= 0) return 0;
    long long up = 1, down = 1;
    while(b){
        up *= a;
        down *= b;
        a--;
        b--;
    }
    return up/down;
}

long long distributeCandies(int n, int limit) {
    return C(n+2, 2)-3*C(n+2-(limit+1), 2)+3*C(n+2-2*(limit+1), 2)-C(n+2-3*(limit+1), 2);
}
