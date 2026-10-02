class Solution {
public:
    int kadane(vector<int>& arr) {
        int curr = arr[0];
        int maxi = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            curr = max(arr[i], curr + arr[i]);
            maxi = max(maxi, curr);
        }

        return maxi;
    }

    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();
        int ans = INT_MIN;

        for (int start = 0; start < n; start++) {

            vector<int> temp;

            for (int i = 0; i < n; i++) {
                temp.push_back(nums[(start + i) % n]);
            }

            ans = max(ans, kadane(temp));
        }

        return ans;
    }
};
//-2
class Solution {
public:
    int kadane(vector<int>& nums) {
        int curr = nums[0];
        int best = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            curr = max(nums[i], curr + nums[i]);
            best = max(best, curr);
        }

        return best;
    }

    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();

        int normal = kadane(nums);

        vector<int> prefix(n), suffix(n), maxPrefix(n);

        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];

        maxPrefix[0] = prefix[0];
        for (int i = 1; i < n; i++)
            maxPrefix[i] = max(maxPrefix[i - 1], prefix[i]);

        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] + nums[i];
        
        int wrap = INT_MIN;

        for (int i = 1; i < n; i++)
            wrap = max(wrap, suffix[i] + maxPrefix[i - 1]);

        return max(normal, wrap);
    }
};
