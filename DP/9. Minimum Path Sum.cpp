class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {

        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return 1e9;

        if(dp[i][j] != -1)
            return dp[i][j];

        int up = solve(i - 1, j, dp, grid);
        int left = solve(i, j - 1, dp, grid);

        return dp[i][j] = grid[i][j] + min(up, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, dp, grid);
    }
};
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                    continue;
                }

                int up = 1e9;
                int left = 1e9;

                if(i > 0)
                    up = grid[i][j] + dp[i-1][j];

                if(j > 0)
                    left = grid[i][j] + dp[i][j-1];

                dp[i][j] = min(up, left);
            }
        }

        return dp[m-1][n-1];
    }
};
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);

        for(int i = 0; i < m; i++) {

            vector<int> curr(n, 0);

            for(int j = 0; j < n; j++) {

                if(i == 0 && j == 0) {
                    curr[j] = grid[i][j];
                    continue;
                }

                int up = 1e9;
                int left = 1e9;

                if(i > 0)
                    up = grid[i][j] + prev[j];

                if(j > 0)
                    left = grid[i][j] + curr[j-1];

                curr[j] = min(up, left);
            }

            prev = curr;
        }

        return prev[n-1];
    }
};