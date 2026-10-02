class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = 0;

        for (int l = 0; l < n; l++) {
            long long sum = 0;

            for (int r = l; r < n; r++) {
                sum += nums[r];

                // Last digit must be x
                if (sum % 10 != x)
                    continue;

                // Find first digit
                long long temp = sum;

                while (temp >= 10) {
                    temp /= 10;
                }

                if (temp == x)
                    ans++;
            }
        }

        return ans;
    }
};