class Solution {
public:

    int solve(int i, int buy, int cap,
              vector<int>& prices,
              vector<vector<vector<int>>>& dp) {

        if (i == prices.size() || cap == 0)
            return 0;

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        if (buy) {
            int take = -prices[i] + solve(i + 1, 0, cap, prices, dp);
            int skip = solve(i + 1, 1, cap, prices, dp);

            return dp[i][buy][cap] = max(take, skip);
        } 
        else {
            int sell = prices[i] + solve(i + 1, 1, cap - 1, prices, dp);
            int hold = solve(i + 1, 0, cap, prices, dp);

            return dp[i][buy][cap] = max(sell, hold);
        }
    }

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2, vector<int>(k + 1, -1))
        );

        return solve(0, 1, k, prices, dp);
    }
};