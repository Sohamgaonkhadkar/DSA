class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2!=0)
            return false;
        int target=sum/2;
        int n=nums.size();
        // Now the problem reduces to finding if there's a subset with sum equal to target
        // We can use the subset sum approach here
        vector<bool> prev(target + 1, false);
        vector<bool> curr(target + 1, false);

        prev[0] = true;

        if(nums[0] <= target)
            prev[nums[0]] = true;

        for(int i = 1; i < n; i++) {

            curr[0] = true;

            for(int t = 1; t <= target; t++) {

                bool notTake = prev[t];

                bool take = false;

                if(nums[i] <= t)
                    take = prev[t - nums[i]];

                curr[t] = take || notTake;
            }

            prev = curr;
        }

        return prev[target];
    }
};