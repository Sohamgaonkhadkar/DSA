class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        while (left<right){
            int width = right - left;
            int minHeight = min(height[left], height[right]);
            int area = width * minHeight;
            maxArea = max(maxArea, area);
            if (height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
    }
};