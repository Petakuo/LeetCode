char kthCharacter(long long k, int* operations, int operationsSize) {
    int doOpe = 0;
    while(k != 1){
        int t = 63-__builtin_clzll(k);
        if((1LL << t) == k) t--;
        k -= (1LL << t);
        if(operations[t]) doOpe++;
    }
    return 'a'+(doOpe%26);
}
