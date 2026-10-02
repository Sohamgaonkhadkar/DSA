class Solution {
public:

    int solve(int i, int j,
              vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {

        int n = triangle.size();

        // Base case: reached last row
        if(i == n - 1)
            return triangle[i][j];

        if(dp[i][j] != -1)
            return dp[i][j];

        int down = triangle[i][j] +
                   solve(i + 1, j, triangle, dp);

        int diag = triangle[i][j] +
                   solve(i + 1, j + 1, triangle, dp);

        return dp[i][j] = min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, 0, triangle, dp);
    }
};
//tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Copy last row
        for(int j = 0; j < n; j++) {
            dp[n-1][j] = triangle[n-1][j];
        }

        // Fill from bottom to top
        for(int i = n-2; i >= 0; i--) {

            for(int j = 0; j <= i; j++) {

                int down = triangle[i][j] + dp[i+1][j];

                int diag = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down, diag);
            }
        }

        return dp[0][0];
    }
};
//space optimization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<int> front = triangle[n-1];

        for(int i = n-2; i >= 0; i--) {

            vector<int> curr(i+1);

            for(int j = 0; j <= i; j++) {

                int down = triangle[i][j] + front[j];

                int diag = triangle[i][j] + front[j+1];

                curr[j] = min(down, diag);
            }

            front = curr;
        }

        return front[0];
    }
};