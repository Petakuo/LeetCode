int maxScoreSightseeingPair(int* values, int valuesSize) {
    int* suffixMax = (int*)malloc(valuesSize*sizeof(int));
    suffixMax[valuesSize-1] = values[valuesSize-1]-(valuesSize-1);
    for(int i = valuesSize-2; i >= 0; i--){
        suffixMax[i] = (values[i]-i) > suffixMax[i+1] ? (values[i]-i) : suffixMax[i+1];
    }
    int max = 0;
    for(int i = 0; i < valuesSize-1; i++){
        max = max > values[i]+i+suffixMax[i+1] ? max : values[i]+i+suffixMax[i+1];
    }
    free(suffixMax);
    return max;
}
