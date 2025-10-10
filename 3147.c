int maximumEnergy(int* energy, int energySize, int k) {
    int ans = INT_MIN;
    for(int i = energySize-k-1; i >= 0; i--){
        energy[i] += energy[i+k];
    }
    for(int i = 0; i < energySize; i++){
        ans = ans > energy[i] ? ans : energy[i];
    }
    return ans;
}
