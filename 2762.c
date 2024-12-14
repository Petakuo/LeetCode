long long continuousSubarrays(int* nums, int numsSize){
    long long sum = 0;
    int left = 0, right = 0;
    int Descent[numsSize], Ascent[numsSize];
    int DeStart = 0, DeEnd = -1, AsStart = 0, AsEnd = -1;
    while(right < numsSize){
        int current = nums[right];
        while(DeEnd >= DeStart && current > Descent[DeEnd]){
            DeEnd--;
        }
        DeEnd++;
        Descent[DeEnd] = current;
        while(AsEnd >= AsStart && current < Ascent[AsEnd]){
            AsEnd--;
        }
        AsEnd++;
        Ascent[AsEnd] = current;
        while(Descent[DeStart]-Ascent[AsStart] > 2){
            if(nums[left] == Descent[DeStart]){
                DeStart++;
            }
            if(nums[left] == Ascent[AsStart]){
                AsStart++;
            }
            left++;
        }
        sum += (right-left+1);
        right++;
    }
    return sum;
}
