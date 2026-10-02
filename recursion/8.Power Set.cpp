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

        // Exclude current element
        solve(idx + 1, nums, temp, ans);
    }
    
    vector<vector<int> > powerSet(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, temp, ans);

        return ans;
    }
};