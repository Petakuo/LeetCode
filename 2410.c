int cmp(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

int matchPlayersAndTrainers(int* players, int playersSize, int* trainers, int trainersSize) {
    qsort(players, playersSize, sizeof(int), cmp);
    qsort(trainers, trainersSize, sizeof(int), cmp);
    int ans = 0, tidx = 0;
    for(int i = 0; i < playersSize; i++){
        while(tidx < trainersSize && players[i] > trainers[tidx]){
            tidx++;
        }
        if(tidx < trainersSize) ans++;
        tidx++;
    }
    return ans;
}
