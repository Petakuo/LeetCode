int findmax(int* arr, int size){
    int max = arr[0];
    int index = 0;
    for(int i = 1; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
            index = i;
        }
    }
    return index;
}

long long pickGifts(int* gifts, int giftsSize, int k) {
    for(k; k > 0; k--){
        int index = findmax(gifts, giftsSize);
        gifts[index] = sqrt(gifts[index]);
    }
    long long sum = 0;
    for(int i = 0; i < giftsSize; i++){
        sum += gifts[i];
    }
    return sum;
}
