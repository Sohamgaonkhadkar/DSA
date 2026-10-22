class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> st;
        int left = 0, ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            st.insert(nums[right]);

            while (*st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[left]));
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};