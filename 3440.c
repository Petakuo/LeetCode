int maxFreeTime(int eventTime, int* startTime, int startTimeSize, int* endTime, int endTimeSize) {
    int ans = 0;
    int leftGap = 0;
    for(int i = 0; i < startTimeSize; i++){
        int left = (i == 0) ? 0 : endTime[i-1];
        int right = (i == startTimeSize-1) ? eventTime : startTime[i+1];
        int time = endTime[i]-startTime[i];
        int diff = leftGap >= time ? 0 : time;
        ans = ans > right-left-diff ? ans : right-left-diff;
        leftGap = leftGap > startTime[i]-left ? leftGap : startTime[i]-left;
    }
    int rightGap = 0;
        for(int i = startTimeSize-1; i >= 0; i--){
        int left = (i == 0) ? 0 : endTime[i-1];
        int right = (i == startTimeSize-1) ? eventTime : startTime[i+1];
        int time = endTime[i]-startTime[i];
        int diff = rightGap >= time ? 0 : time;
        ans = ans > right-left-diff ? ans : right-left-diff;
        rightGap = rightGap > right-endTime[i] ? rightGap : right-endTime[i];
    }
    return ans;
}
