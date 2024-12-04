int distanceTraveled(int mainTank, int additionalTank) {
    int ans = mainTank*10;
    int add = 0;
    while((mainTank-5 >= 0) && additionalTank > 0){
        mainTank -= 4;
        additionalTank -= 1;
        add += 10;
    }
    return ans+add;
}
