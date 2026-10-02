class Solution {
public:

    int f(int ind, int len,
          vector<int>& price,
          vector<vector<int>>& dp) {

        if(ind == 0) {
            return len * price[0];
        }

        if(dp[ind][len] != -1)
            return dp[ind][len];

        int notTake = f(ind - 1, len, price, dp);

        int take = 0;

        int rodLength = ind + 1;

        if(rodLength <= len)
            take = price[ind] +
                   f(ind, len - rodLength,
                     price, dp);

        return dp[ind][len] = max(take, notTake);
    }

    int rodCutting(vector<int>& price, int n) {

        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, -1)
        );

        return f(n - 1, n, price, dp);
    }
};
//tabulation
class Solution{
public:

    int rodCutting(vector<int> price, int n) {

        vector<int> prev(n + 1, 0);

        // Base case
        for(int len = 0; len <= n; len++) {
            prev[len] = len * price[0];
        }

        for(int i = 1; i < n; i++) {

            vector<int> curr(n + 1, 0);

            int rodLength = i + 1;

            for(int len = 0; len <= n; len++) {

                int notTake = prev[len];

                int take = 0;

                if(rodLength <= len)
                    take = price[i] +
                           curr[len - rodLength];

                curr[len] = max(take, notTake);
            }

            prev = curr;
        }

        return prev[n];
    }
};