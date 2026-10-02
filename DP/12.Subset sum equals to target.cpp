class Solution {
public:

    bool solve(int i, int target,
               vector<int>& arr,
               vector<vector<int>>& dp) {

        if(target == 0) return true;

        if(i == 0)
            return arr[0] == target;

        if(dp[i][target] != -1)
            return dp[i][target];

        bool notTake =
            solve(i-1,target,arr,dp);

        bool take = false;

        if(arr[i] <= target)
            take =
                solve(i-1,target-arr[i],arr,dp);

        return dp[i][target] = take || notTake;
    }

    bool subsetSumToK(vector<int>& arr, int target) {

        int n = arr.size();

        vector<vector<int>> dp(
            n,
            vector<int>(target+1,-1)
        );

        return solve(n-1,target,arr,dp);
    }
};
//tabulation
class Solution {
public:
    bool subsetSumToK(vector<int>& arr, int target) {

        int n = arr.size();

        vector<vector<bool>> dp(
            n,
            vector<bool>(target+1,false)
        );

        for(int i=0;i<n;i++)
            dp[i][0] = true;

        if(arr[0] <= target)
            dp[0][arr[0]] = true;

        for(int i=1;i<n;i++) {

            for(int t=1;t<=target;t++) {

                bool notTake = dp[i-1][t];

                bool take = false;

                if(arr[i] <= t)
                    take = dp[i-1][t-arr[i]];

                dp[i][t] = take || notTake;
            }
        }

        return dp[n-1][target];
    }
};
//space optimization
class Solution {
public:
    bool subsetSumToK(vector<int>& arr, int target) {

        int n = arr.size();

        vector<bool> prev(target + 1, false);
        vector<bool> curr(target + 1, false);

        prev[0] = true;

        if(arr[0] <= target)
            prev[arr[0]] = true;

        for(int i = 1; i < n; i++) {

            curr[0] = true;

            for(int t = 1; t <= target; t++) {

                bool notTake = prev[t];

                bool take = false;

                if(arr[i] <= t)
                    take = prev[t - arr[i]];

                curr[t] = take || notTake;
            }

            prev = curr;
        }

        return prev[target];
    }
};
