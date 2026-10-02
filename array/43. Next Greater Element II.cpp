class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, -1);
        stack<pair<int, int>> st;

        for (int i = 0; i < 2 * n; i++) {
            int x = nums[i % n];

            while (!st.empty() && st.top().second < x) {
                ans[st.top().first] = x;
                st.pop();
            }

            if (i < n) {
                st.push({i, x});
            }
        }

        return ans;
    }
};