//memoization
class Solution {
public:

    int solve(int ind,
              vector<int>& h,
              vector<int>& dp,
              int k) {

        if(ind == 0)
            return 0;

        if(dp[ind] != -1)
            return dp[ind];

        int mini = INT_MAX;

        for(int j = 1; j <= k; j++) {

            if(ind - j >= 0) {

                int jump =
                    solve(ind - j, h, dp, k)
                    + abs(h[ind] - h[ind - j]);

                mini = min(mini, jump);
            }
        }

        return dp[ind] = mini;
    }

    int frogJump(vector<int>& heights, int k) {

        int n = heights.size();

        vector<int> dp(n, -1);

        return solve(n - 1, heights, dp, k);
    }
};
/tabulation
class Solution {
public:

    int frogJump(vector<int>& h, int k) {

        int n = h.size();

        vector<int> dp(n);

        dp[0] = 0;

        for(int i = 1; i < n; i++) {

            int mini = INT_MAX;

            for(int j = 1; j <= k; j++) {

                if(i - j >= 0) {

                    int jump =
                        dp[i-j]
                        + abs(h[i] - h[i-j]);

                    mini = min(mini, jump);
                }
            }

            dp[i] = mini;
        }

        return dp[n-1];
    }
};