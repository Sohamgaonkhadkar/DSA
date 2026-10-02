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

            solve(idx + 1,
                  nums,
                  sum + nums[idx],
                  temp,
                  ans,
                  k);

            temp.pop_back();
        }

        // Skip duplicates
        int next = idx + 1;

        while (next < nums.size() &&
               nums[next] == nums[idx]) {

            next++;
        }

        // Exclude current element and duplicates
        solve(next,
              nums,
              sum,
              temp,
              ans,
              k);
    }

    vector<vector<int>> combinationSum2(vector<int>& nums,
                                        int k) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, 0, temp, ans, k);

        return ans;
    }
};