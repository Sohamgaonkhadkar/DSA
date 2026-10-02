class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        int N = nums.size();
        int n = N / 2;

        long long total = 0;
        for (int x : nums) total += x;

        vector<vector<long long>> left(n + 1), right(n + 1);

        // Generate subset sums
        for (int mask = 0; mask < (1 << n); mask++) {

            long long sumL = 0;
            long long sumR = 0;
            int cnt = 0;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    cnt++;
                    sumL += nums[i];
                    sumR += nums[i + n];
                }
            }

            left[cnt].push_back(sumL);
            right[cnt].push_back(sumR);
        }

        for (int i = 0; i <= n; i++) {
            sort(right[i].begin(), right[i].end());
        }

        long long ans = LLONG_MAX;

        for (int cntL = 0; cntL <= n; cntL++) {

            int cntR = n - cntL;

            for (long long sumL : left[cntL]) {

                long long target = total / 2 - sumL;

                auto &vec = right[cntR];

                auto it = lower_bound(
                    vec.begin(),
                    vec.end(),
                    target
                );

                if (it != vec.end()) {
                    long long chosen = sumL + *it;
                    ans = min(ans,
                              llabs(total - 2 * chosen));
                }

                if (it != vec.begin()) {
                    --it;
                    long long chosen = sumL + *it;
                    ans = min(ans,
                              llabs(total - 2 * chosen));
                }
            }
        }

        return (int)ans;
    }
};