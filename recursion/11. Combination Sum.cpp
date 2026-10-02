class Solution {
public:

    void solve(int idx,
               vector<int>& nums,
               int sum,
               vector<int>& temp,
               vector<vector<int>>& ans,
               int k) {

        // Base case
        if (idx == nums.size()) {

            if (sum == k) {
                ans.push_back(temp);
            }

            return;
        }

        // Include current element
       if (sum + nums[idx] <= k) {

            temp.push_back(nums[idx]);

            // stay on same index
            solve(idx,
                  nums,
                  sum + nums[idx],
                  temp,
                  ans,
                  k);

            temp.pop_back();
        }
        // Exclude current element
        solve(idx + 1,
              nums,
              sum,
              temp,
              ans,
              k);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int k) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, 0, temp, ans, k);

        return ans;
    }
};