int countSymmetricIntegers(int low, int high) {
    int count = 0;
    for(int i = low; i <= high; i++){
        int n = 0, temp = i;
        while(temp){
            temp /= 10;
            n++;
        }
        if((n&1) == 1) continue;
        n /= 2;
        int right = 0, left = 0;
        temp = i;
        while(n){
            right += temp%10;
            temp /= 10;
            n--;
        }
        while(temp){
            left += temp%10;
            temp /= 10;
        }
        count += (left == right);
    }
    return count;
}
