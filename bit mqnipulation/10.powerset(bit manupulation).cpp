class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> ans;

        int total = 1 << n;

        for(int mask = 0; mask < total; mask++) {

            vector<int> temp;

            for(int i = 0; i < n; i++) {

                // Check if i-th bit is set
                if(mask & (1 << i)) {
                    temp.push_back(nums[i]);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};