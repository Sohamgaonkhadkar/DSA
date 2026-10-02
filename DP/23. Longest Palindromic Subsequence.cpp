class Solution {
public:

    int f(int i, int j,
          string &s,
          string &rev,
          vector<vector<int>>& dp) {

        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == rev[j])
            return dp[i][j] =
                1 + f(i-1, j-1, s, rev, dp);

        return dp[i][j] =
            max(
                f(i-1, j, s, rev, dp),
                f(i, j-1, s, rev, dp)
            );
    }

    int longestPalindromeSubseq(string s) {

        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.size();

        vector<vector<int>> dp(
            n,
            vector<int>(n, -1)
        );

        return f(n-1, n-1, s, rev, dp);
    }
};
//space optimization
class Solution {
public:

    int longestPalindromeSubseq(string s) {

        string rev = s;
        reverse(rev.begin(), rev.end());

        int n = s.size();

        vector<int> prev(n+1, 0);

        for(int i=1;i<=n;i++) {

            vector<int> curr(n+1, 0);

            for(int j=1;j<=n;j++) {

                if(s[i-1] == rev[j-1])
                    curr[j] =
                        1 + prev[j-1];

                else
                    curr[j] =
                        max(prev[j],
                            curr[j-1]);
            }

            prev = curr;
        }

        return prev[n];
    }
};