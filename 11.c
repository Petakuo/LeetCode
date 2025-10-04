int maxArea(int* height, int heightSize) {
    int ans = 0, left = 0, right = heightSize-1;
    while(left < right){
        int h = height[left] < height[right] ? height[left] : height[right];
        int water = (right-left)*h;
        ans = ans > water ? ans : water;
        if(height[left] < height[right]) left++;
        else if(height[left] > height[right]) right--;
        else{
            left++;
            right--;
        }
    }
    return ans;
}
