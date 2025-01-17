bool doesValidArrayExist(int* derived, int derivedSize) {
    int XOR = derived[0];
    for(int i = 1; i < derivedSize; i++){
        XOR ^= derived[i];
    }
    return XOR^1;
}
