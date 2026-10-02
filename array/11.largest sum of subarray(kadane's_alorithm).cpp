class Solution {
public:
    int maxProduct(vector<int>& nums) {
            int curr = nums[0];
            int maxSum = nums[0];

            for (int i = 1; i < nums.size(); i++) {
                curr = max(nums[i], curr + nums[i]);
                maxSum = max(maxSum, curr);
            }
            return maxSum;
    }
};