class Solution {
public:
    int minDistance(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        vector<int> prev(m + 1, 0);

        // Base case: converting "" to s2
        for(int j = 0; j <= m; j++)
            prev[j] = j;

        for(int i = 1; i <= n; i++) {

            vector<int> curr(m + 1, 0);

            // Base case: converting s1[0..i-1] to ""
            curr[0] = i;

            for(int j = 1; j <= m; j++) {

                if(s1[i - 1] == s2[j - 1]) {
                    curr[j] = prev[j - 1];
                }
                else {

                    int insertOp  = 1 + curr[j - 1];
                    int deleteOp  = 1 + prev[j];
                    int replaceOp = 1 + prev[j - 1];

                    curr[j] = min({insertOp,
                                   deleteOp,
                                   replaceOp});
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};
//memoization
class Solution {
public:
    int solve(int i, int j,
              string &s1, string &s2,
              vector<vector<int>> &dp) {

        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j])
            return dp[i][j] =
                solve(i - 1, j - 1, s1, s2, dp);

        int insertOp =
            1 + solve(i, j - 1, s1, s2, dp);

        int deleteOp =
            1 + solve(i - 1, j, s1, s2, dp);

        int replaceOp =
            1 + solve(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] =
            min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(
            n, vector<int>(m, -1));

        return solve(n - 1, m - 1,
                     s1, s2, dp);
    }
};