class Solution {
public:

    bool solve(int idx,
               vector<int>& nums,
               int sum,
               int k) {

        // Base case
        if (idx == nums.size()) {
            return (sum == k);
        }

        // Include current element
        bool left =
            solve(idx + 1,
                  nums,
                  sum + nums[idx],
                  k);

        // Exclude current element
        bool right =
            solve(idx + 1,
                  nums,
                  sum,
                  k);

        return left || right;
    }

    bool checkSubsequenceSum(vector<int>& nums, int k) {

        return solve(0, nums, 0, k);
    }
};