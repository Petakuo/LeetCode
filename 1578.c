int minCost(char* colors, int* neededTime, int neededTimeSize) {
    int ans = 0;
    for(int i = 0; i < neededTimeSize-1; i++){
        if(colors[i] == colors[i+1]){
            int temp = neededTime[i], max = neededTime[i];
            while(colors[i] == colors[i+1] && i+1 < neededTimeSize){
                temp += neededTime[i+1];
                if(neededTime[i+1] > max) max = neededTime[i+1];
                i++;
            }
            ans += temp-max;
        }
    }
    return ans;
}
