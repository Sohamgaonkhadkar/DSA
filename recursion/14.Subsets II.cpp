class Solution {
public:
    void solve(int idx,
               vector<int>& nums,
               vector<int>& temp,
               vector<vector<int>>& ans){

        // Base case
        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }

        // Include current element
        temp.push_back(nums[idx]);

        solve(idx + 1, nums, temp, ans);

        temp.pop_back();
        // Skip duplicates
        int next = idx + 1;

        while (next < nums.size() &&
               nums[next] == nums[idx]) {

            next++;
        }

        // Exclude current element
        solve(next, nums, temp, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());

        solve(0, nums, temp, ans);

        return ans;
    }
};

//-2
class Solution {
public:

    void solve(int idx,
               vector<int>& nums,
               vector<int>& temp,
               vector<vector<int>>& ans){

        // Store current subset
        ans.push_back(temp);

        for(int i = idx; i < nums.size(); i++){

            // Skip duplicates
            if(i > idx && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);

            solve(i + 1, nums, temp, ans);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, temp, ans);

        return ans;
    }
};