class Solution {
public:

    int f(int ind, int W,
          vector<int>& val,
          vector<int>& wt,
          vector<vector<int>>& dp) {

        if(ind == 0) {
            return (W / wt[0]) * val[0];
        }

        if(dp[ind][W] != -1)
            return dp[ind][W];

        int notTake = f(ind - 1, W, val, wt, dp);

        int take = 0;
        if(wt[ind] <= W)
            take = val[ind] +
                   f(ind, W - wt[ind], val, wt, dp);

        return dp[ind][W] = max(take, notTake);
    }

    int knapSack(vector<int>& val,
                 vector<int>& wt,
                 int W) {

        int n = val.size();

        vector<vector<int>> dp(
            n,
            vector<int>(W + 1, -1)
        );

        return f(n - 1, W, val, wt, dp);
    }
};
//tabulation
class Solution {
public:

    int knapSack(vector<int>& val,
                 vector<int>& wt,
                 int W) {

        int n = val.size();

        vector<vector<int>> dp(n,
                               vector<int>(W + 1, 0));

        // Base Case
        for(int w = 0; w <= W; w++) {
            dp[0][w] = (w / wt[0]) * val[0];
        }

        for(int i = 1; i < n; i++) {

            for(int w = 0; w <= W; w++) {

                int notTake = dp[i-1][w];

                int take = 0;
                if(wt[i] <= w)
                    take = val[i] +
                           dp[i][w - wt[i]]; // same row

                dp[i][w] = max(take, notTake);
            }
        }

        return dp[n-1][W];
    }
};
//space optimization
class Solution {
public:

    int knapSack(vector<int>& val,
                 vector<int>& wt,
                 int W) {

        int n = val.size();

        vector<int> prev(W + 1, 0);

        for(int w = 0; w <= W; w++) {
            prev[w] = (w / wt[0]) * val[0];
        }

        for(int i = 1; i < n; i++) {

            vector<int> curr(W + 1, 0);

            for(int w = 0; w <= W; w++) {

                int notTake = prev[w];

                int take = 0;
                if(wt[i] <= w)
                    take = val[i] +
                           curr[w - wt[i]]; // same row

                curr[w] = max(take, notTake);
            }

            prev = curr;
        }

        return prev[W];
    }
};