char* intToRoman(int num) {
    int temp = num, digits = 0;
    while(temp){
        temp /= 10;
        digits++;
    }
    char* ans = (char*)malloc((4*digits+1)*sizeof(char));
    int size = 0;
    if(num > 999){
        int a = num/1000;
        while(a){
            ans[size++] = 'M';
            a--;
        }
        num %= 1000;
    }
    if(num > 99){
        int a = num/100;
        if(a == 4){
            ans[size++] = 'C';
            ans[size++] = 'D';
        }
        else if(a == 9){
            ans[size++] = 'C';
            ans[size++] = 'M';
        }
        else if(a >= 5){
            ans[size++] = 'D';
            a -= 5;
            while(a){
                ans[size++] = 'C';
                a--;
            }
        }
        else{
            while(a){
                ans[size++] = 'C';
                a--;
            }
        }
        num %= 100;
    }
    if(num > 9){
        int a = num/10;
        if(a == 4){
            ans[size++] = 'X';
            ans[size++] = 'L';
        }
        else if(a == 9){
            ans[size++] = 'X';
            ans[size++] = 'C';
        }
        else if(a >= 5){
            ans[size++] = 'L';
            a -= 5;
            while(a){
                ans[size++] = 'X';
                a--;
            }
        }
        else{
            while(a){
                ans[size++] = 'X';
                a--;
            }
        }
        num %= 10;
    }
    if(num == 4){
        ans[size++] = 'I';
        ans[size++] = 'V';
    }
    else if(num == 9){
        ans[size++] = 'I';
        ans[size++] = 'X';
    }
    else if(num >= 5){
        ans[size++] = 'V';
        num -= 5;
        while(num){
            ans[size++] = 'I';
            num--;
        }
    }
    else{
        while(num){
            ans[size++] = 'I';
            num--;
        }
    }
    ans[size] = '\0';
    return ans;
}
