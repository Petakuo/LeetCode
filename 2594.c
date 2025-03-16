long long repairCars(int* ranks, int ranksSize, int cars) {
    long long min = 1, max = ranks[0];
    for(int i = 0; i < ranksSize; i++){
        if(ranks[i] > max) max = ranks[i];
    }
    max = max*cars*cars;
    while(min < max){
        long long mid = min+(max-min)/2;
        long long nowCar = 0;
        for(int i = 0; i < ranksSize; i++){
            nowCar += sqrt(mid/ranks[i]);
        }
        if(nowCar >= cars) max = mid;
        if(nowCar < cars) min = mid+1;
    }
    return min;
}
