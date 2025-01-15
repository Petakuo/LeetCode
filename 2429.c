int minimizeXor(int num1, int num2) {
    int count1 = __builtin_popcount(num1);
    int count2 = __builtin_popcount(num2);
    int ans = num1;
    if(count1 < count2){
        int one = count2-count1;
        int shift = 0, or = 0;
        while(one != 0){
            if((num1 & 1) == 1) num1 >>= 1;
            else if((num1 & 1) == 0){
                num1 >>= 1;
                or |= 1 << shift;
                one--;
            }
            shift++;
        }
        ans |= or;
    }
    else if(count1 > count2){
        int right = count1-count2;
        int shift = 0;
        while(right != 0){
            if((num1 & 1) == 0) num1 >>= 1;
            else if((num1 & 1) == 1){
                num1 >>= 1;
                right--;
            }
            shift++;
        }
        ans = (ans >> shift) << shift;
    }
    return ans;
}
