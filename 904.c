int totalFruit(int* fruits, int fruitsSize) {
    int left = 0, right = 0;
    int ans = 0;
    int fruitNum[100001] = {0}, type = 0;
    while(right < fruitsSize){
        if(fruitNum[fruits[right]] == 0) type++;
        fruitNum[fruits[right]]++;
        while(type > 2){
            fruitNum[fruits[left]]--;
            if(fruitNum[fruits[left]] == 0) type--;
            left++;
        }
        ans = ans > (right-left)+1 ? ans : (right-left)+1;
        right++;
    }
    return ans;
}
