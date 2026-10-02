class Solution {
public:

    int solve(int i, int j1, int j2,
              vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {

        int n = grid.size();
        int m = grid[0].size();

        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e8;

        if(i == n - 1) {
            if(j1 == j2)
                return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int ans = -1e8;

        for(int dj1 = -1; dj1 <= 1; dj1++) {
            for(int dj2 = -1; dj2 <= 1; dj2++) {

                int value;

                if(j1 == j2)
                    value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];

                value += solve(i + 1,
                               j1 + dj1,
                               j2 + dj2,
                               grid,
                               dp);

                ans = max(ans, value);
            }
        }

        return dp[i][j1][j2] = ans;
    }

    int maxChocolates(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(m,
            vector<int>(m, -1))
        );

        return solve(0, 0, m - 1, grid, dp);
    }
};
//tabulation
class Solution {
public:
    int maxChocolates(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(m, vector<int>(m, 0))
        );

        // Base case
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {

                if(j1 == j2)
                    dp[n-1][j1][j2] = grid[n-1][j1];
                else
                    dp[n-1][j1][j2] =
                        grid[n-1][j1] + grid[n-1][j2];
            }
        }

        for(int i = n - 2; i >= 0; i--) {

            for(int j1 = 0; j1 < m; j1++) {

                for(int j2 = 0; j2 < m; j2++) {

                    int maxi = -1e8;

                    for(int dj1 = -1; dj1 <= 1; dj1++) {

                        for(int dj2 = -1; dj2 <= 1; dj2++) {

                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;

                            int value;

                            if(j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            if(nj1 >= 0 && nj1 < m &&
                               nj2 >= 0 && nj2 < m)
                            {
                                value += dp[i+1][nj1][nj2];
                            }
                            else {
                                value += -1e8;
                            }

                            maxi = max(maxi, value);
                        }
                    }

                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][m-1];
    }
};
//space optimization
class Solution {
public:
    int maxChocolates(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> front(m, vector<int>(m, 0));
        vector<vector<int>> curr(m, vector<int>(m, 0));

        // Base Case (last row)
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {

                if(j1 == j2)
                    front[j1][j2] = grid[n-1][j1];
                else
                    front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        for(int i = n - 2; i >= 0; i--) {

            for(int j1 = 0; j1 < m; j1++) {

                for(int j2 = 0; j2 < m; j2++) {

                    int maxi = -1e8;

                    for(int dj1 = -1; dj1 <= 1; dj1++) {

                        for(int dj2 = -1; dj2 <= 1; dj2++) {

                            int value;

                            if(j1 == j2)
                                value = grid[i][j1];
                            else
                                value = grid[i][j1] + grid[i][j2];

                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;

                            if(nj1 >= 0 && nj1 < m &&
                               nj2 >= 0 && nj2 < m)
                            {
                                value += front[nj1][nj2];
                            }
                            else {
                                value += -1e8;
                            }

                            maxi = max(maxi, value);
                        }
                    }

                    curr[j1][j2] = maxi;
                }
            }

            front = curr;
        }

        return front[0][m-1];
    }
};