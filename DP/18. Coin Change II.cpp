class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<long long> prev(amount + 1, 0);

        for(int t = 0; t <= amount; t++) {
            if(t % coins[0] == 0)
                prev[t] = 1;
        }

        for(int i = 1; i < n; i++) {

            vector<long long> curr(amount + 1, 0);

            for(int t = 0; t <= amount; t++) {

                long long notTake = prev[t];

                long long take = 0;

                if(coins[i] <= t)
                    take = curr[t - coins[i]];

                curr[t] = (take + notTake)%1000000007;
            }

            prev = curr;
        }

        return (int)prev[amount];
    }
};
//memoization
class Solution {
public:

    int f(int ind, int amount,
          vector<int>& coins,
          vector<vector<int>>& dp) {

        if(ind == 0) {
            return (amount % coins[0] == 0);
        }

        if(dp[ind][amount] != -1)
            return dp[ind][amount];

        int notTake = f(ind - 1, amount, coins, dp);

        int take = 0;
        if(coins[ind] <= amount)
            take = f(ind, amount - coins[ind], coins, dp);

        return dp[ind][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(
            n,
            vector<int>(amount + 1, -1)
        );

        return f(n - 1, amount, coins, dp);
    }
};