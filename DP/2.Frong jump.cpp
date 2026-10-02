Memoization
class Solution {
public:

    int solve(int ind, vector<int>& h, vector<int>& dp) {

        if(ind == 0) return 0;

        if(dp[ind] != -1)
            return dp[ind];

        int oneJump =
            solve(ind - 1, h, dp)
            + abs(h[ind] - h[ind - 1]);

        int twoJump = INT_MAX;

        if(ind > 1) {
            twoJump =
                solve(ind - 2, h, dp)
                + abs(h[ind] - h[ind - 2]);
        }

        return dp[ind] = min(oneJump, twoJump);
    }

    int frogJump(vector<int>& heights) {

        int n = heights.size();

        vector<int> dp(n, -1);

        return solve(n - 1, heights, dp);
    }
};
//space optimized DP
class Solution {
public:
    int frogJump(vector<int>& h) {

        int n = h.size();

        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for(int i = 1; i < n; i++) {

            int oneJump =
                prev1 + abs(h[i] - h[i - 1]);

            int twoJump = INT_MAX;

            if(i > 1) {
                twoJump =
                    prev2 + abs(h[i] - h[i - 2]);
            }

            int curr = min(oneJump, twoJump);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
//Tabulation    
class Solution {
public:

    int frogJump(vector<int>& h) {

        int n = h.size();

        vector<int> dp(n);

        dp[0] = 0;

        for(int i = 1; i < n; i++) {

            int oneJump =
                dp[i - 1]
                + abs(h[i] - h[i - 1]);

            int twoJump = INT_MAX;

            if(i > 1) {
                twoJump =
                    dp[i - 2]
                    + abs(h[i] - h[i - 2]);
            }

            dp[i] = min(oneJump, twoJump);
        }

        return dp[n - 1];
    }
};