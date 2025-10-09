long long minTime(int* skill, int skillSize, int* mana, int manaSize) {
    long long* time = (long long*)calloc(skillSize, sizeof(long long));
    for(int i = 0; i < manaSize; i++){
        long long cur = 0;
        for(int j = 0; j < skillSize; j++){
            cur = (cur > time[j] ? cur : time[j])+skill[j]*mana[i];
        }
        time[skillSize-1] = cur;
        for(int j = skillSize-2; j >= 0; j--){
            time[j] = time[j+1]-(long long)skill[j+1]*mana[i];
        }
    }
    long long ans = time[skillSize-1];
    free(time);
    return ans;
}
