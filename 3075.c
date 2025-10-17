int cmp(const void* a, const void* b){
    return *(int*)b-*(int*)a;
}

long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
    long long ans = 0;
    qsort(happiness, happinessSize, sizeof(int), cmp);
    int temp = 0;
    for(int i = 0; i < happinessSize; i++){
        if(temp != k){
            int add = happiness[i]-temp;
            ans = add < 0 ? ans : ans+add;
            temp++;
        }
        else break;
    }
    return ans;
}
