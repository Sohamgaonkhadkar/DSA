class Solution {
public:

    int solve(int day, int last,
              vector<vector<int>>& points,
              vector<vector<int>>& dp) {
                                                        
        if(day == 0) {

            int maxi = 0;

            for(int task = 0; task < 3; task++) {
                if(task != last)
                    maxi = max(maxi, points[0][task]);
            }

            return maxi;
        }

        if(dp[day][last] != -1)
            return dp[day][last];

        int maxi = 0;

        for(int task = 0; task < 3; task++) {

            if(task != last) {

                int cur =
                    points[day][task] +
                    solve(day - 1, task, points, dp);

                maxi = max(maxi, cur);
            }
        }

        return dp[day][last] = maxi;
    }

    int ninjaTraining(vector<vector<int>>& points) {

        int n = points.size();

        vector<vector<int>> dp(n, vector<int>(4, -1));

        return solve(n - 1, 3, points, dp);
    }
};

class Solution {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        
        dp[0][0] = matrix[0][0];
        dp[0][1] = matrix[0][1];
        dp[0][2] = matrix[0][2];
        
        for(int i = 1; i < n; i++) {
            dp[i][0] = matrix[i][0] + max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = matrix[i][1] + max(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = matrix[i][2] + max(dp[i-1][0], dp[i-1][1]);
        }
        
        return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};
//space optimization
class Solution {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<int> prev(3);

        prev[0] = matrix[0][0];
        prev[1] = matrix[0][1];
        prev[2] = matrix[0][2];

        for(int i = 1; i < n; i++) {

            vector<int> cur(3);

            cur[0] = matrix[i][0] + max(prev[1], prev[2]);
            cur[1] = matrix[i][1] + max(prev[0], prev[2]);
            cur[2] = matrix[i][2] + max(prev[0], prev[1]);

            prev = cur;
        }

        return max({prev[0], prev[1], prev[2]});
    }
};