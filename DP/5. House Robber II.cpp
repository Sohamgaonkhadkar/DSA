class Solution {
public:

    int solve(vector<int>& arr) {

        int n = arr.size();

        vector<int> dp(n);

        dp[0] = arr[0];

        for(int i = 1; i < n; i++) {

            int pick = arr[i];

            if(i > 1)
                pick += dp[i - 2];

            int notPick = dp[i - 1];

            dp[i] = max(pick, notPick);
        }

        return dp[n - 1];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> temp1, temp2;

        // Exclude last house
        for(int i = 0; i < n - 1; i++)
            temp1.push_back(nums[i]);

        // Exclude first house
        for(int i = 1; i < n; i++)
            temp2.push_back(nums[i]);

        return max(solve(temp1), solve(temp2));
    }
};
class Solution {
public:

    int solve(vector<int>& nums, int l, int r) {

        int n = r - l + 1;

        vector<int> dp(n);

        dp[0] = nums[l];

        for(int i = 1; i < n; i++) {

            int pick = nums[l + i];

            if(i > 1)
                pick += dp[i - 2];

            int notPick = dp[i - 1];

            dp[i] = max(pick, notPick);
        }

        return dp[n - 1];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        return max(
            solve(nums, 0, n - 2),
            solve(nums, 1, n - 1)
        );
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];

        int prev1 = nums[0]; // dp[i-1]
        int prev2 = 0;       // dp[i-2]

        for(int i = 1; i < n-1; i++) {

            int pick = nums[i] + prev2;
            int notPick = prev1;

            int cur = max(pick, notPick);

            prev2 = prev1;
            prev1 = cur;
        }

        int prev11=nums[1];
        int prev22=0;
        for(int i = 2; i < n; i++) {

            int pick = nums[i] + prev22;
            int notPick = prev11;

            int cur = max(pick, notPick);

            prev22 = prev11;
            prev11 = cur;
        }
        return max(prev11,prev1);
    }
};