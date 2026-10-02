class Solution {
public:
    bool solve(int i, int j, string &s, string &p,
               vector<vector<int>> &dp) {

        // Both strings exhausted
        if(i < 0 && j < 0)
            return true;

        // Pattern exhausted but string remains
        if(j < 0)
            return false;

        // String exhausted
        if(i < 0) {
            for(int k = 0; k <= j; k++) {
                if(p[k] != '*')
                    return false;
            }
            return true;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        // Characters match or '?'
        if(s[i] == p[j] || p[j] == '?')
            return dp[i][j] =
                solve(i - 1, j - 1, s, p, dp);

        // '*'
        if(p[j] == '*')
            return dp[i][j] =
                solve(i, j - 1, s, p, dp) ||   // match empty
                solve(i - 1, j, s, p, dp);     // match one/more chars

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n,
                               vector<int>(m, -1));

        return solve(n - 1, m - 1, s, p, dp);
    }
};
//space optimization
class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<bool> prev(m + 1, false);

        prev[0] = true;

        for(int j = 1; j <= m; j++) {

            bool flag = true;

            for(int k = 1; k <= j; k++) {
                if(p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }

            prev[j] = flag;
        }

        for(int i = 1; i <= n; i++) {

            vector<bool> curr(m + 1, false);

            for(int j = 1; j <= m; j++) {

                if(s[i - 1] == p[j - 1] ||
                   p[j - 1] == '?')
                {
                    curr[j] = prev[j - 1];
                }

                else if(p[j - 1] == '*')
                {
                    curr[j] =
                        curr[j - 1] ||   // dp[i][j-1]
                        prev[j];         // dp[i-1][j]
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};