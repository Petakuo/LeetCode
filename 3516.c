int findClosest(int x, int y, int z) {
    int one = abs(x-z);
    int two = abs(y-z);
    if(one < two) return 1;
    else if(one == two) return 0;
    else return 2;
}
