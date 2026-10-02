class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {

        if(i == 0) return nums[0];
        if(i < 0) return 0;

        if(dp[i] != -1)
            return dp[i];

        int pick = nums[i] + solve(i - 2, nums, dp);
        int notPick = solve(i - 1, nums, dp);

        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, -1);

        return solve(n - 1, nums, dp);
    }
};
//tabulation
class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> dp(n);

        dp[0] = nums[0];

        for(int i = 1; i < n; i++) {

            int pick = nums[i];

            if(i > 1)
                pick += dp[i - 2];

            int notPick = dp[i - 1];

            dp[i] = max(pick, notPick);
        }

        return dp[n - 1];
    }
};
//space optimization
class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];

        int prev1 = nums[0]; // dp[i-1]
        int prev2 = 0;       // dp[i-2]

        for(int i = 1; i < n; i++) {

            int pick = nums[i] + prev2;
            int notPick = prev1;

            int cur = max(pick, notPick);

            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};
0 7 15 9 15 9
0 0 15 0 0 1