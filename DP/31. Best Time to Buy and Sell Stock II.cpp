class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, int buy, vector<int>& prices) {
        if (i == n)
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        if (buy) {
            int take = -prices[i] + solve(i + 1, 0, prices);
            int skip = solve(i + 1, 1, prices);

            return dp[i][buy] = max(take, skip);
        } 
        else {
            int sell = prices[i] + solve(i + 1, 1, prices);
            int hold = solve(i + 1, 0, prices);

            return dp[i][buy] = max(sell, hold);
        }
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n, vector<int>(2, -1));

        return solve(0, 1, prices);
    }
};
//-2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};