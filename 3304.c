char kthCharacter(int k) {
    int operation = 0;
    while(k != 1){
        int cur = 1;
        while(cur < k){
            cur *= 2;
        }
        k -= cur/2;
        operation++;
    }
    return 'a'+operation;
}
