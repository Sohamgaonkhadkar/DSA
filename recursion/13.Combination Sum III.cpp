class Solution {
public:

    void solve(int idx,
               vector<int>& nums,
               int sum,
               vector<int>& temp,
               vector<vector<int>>& ans,
               int k,
               int n) {

        // Valid combination
        if(temp.size() == k) {

            if(sum == n) {
                ans.push_back(temp);
            }

            return;
        }

        // Out of bounds
        if(idx >= nums.size())
            return;

        // Include
        if(sum + nums[idx] <= n) {

            temp.push_back(nums[idx]);

            solve(idx + 1,
                  nums,
                  sum + nums[idx],
                  temp,
                  ans,
                  k,
                  n);

            temp.pop_back();
        }

        // Exclude
        solve(idx + 1,
              nums,
              sum,
              temp,
              ans,
              k,
              n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> nums = {1,2,3,4,5,6,7,8,9};

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, 0, temp, ans, k, n);

        return ans;
    }
};