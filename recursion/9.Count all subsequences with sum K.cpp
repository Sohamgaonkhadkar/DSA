class Solution {
public:

    int solve(int idx,
              vector<int>& nums,
              int sum,
              int k){

        // Base case
        if(idx == nums.size()){

            if(sum == k)
                return 1;

            return 0;
        }

        // Include current element
        int left =
            solve(idx + 1,
                  nums,
                  sum + nums[idx],
                  k);

        // Exclude current element
        int right =
            solve(idx + 1,
                  nums,
                  sum,
                  k);

        return left + right;
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {

        return solve(0, nums, 0, k);
    }
};