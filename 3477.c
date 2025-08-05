int numOfUnplacedFruits(int* fruits, int fruitsSize, int* baskets, int basketsSize) {
    int ans = 0;
    for(int i = 0; i < fruitsSize; i++){
        bool placed = 0;
        for(int j = 0; j < basketsSize; j++){
            if(fruits[i] <= baskets[j]){
                baskets[j] = -1;
                placed = 1;
                break;
            }
        }
        if(placed == 0) ans++;
    }
    return ans;
}
