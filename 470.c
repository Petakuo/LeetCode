// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

int rand10() {
    while(1){
        int r = (rand7()-1)*7+rand7();
        if(r <= 40) return (r-1)%10+1;
    }
}
