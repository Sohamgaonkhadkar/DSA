class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int len = s.size();

        // 1. Find pivot
        int i = len - 2;

        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }

        // No greater permutation
        if (i < 0)
            return -1;

        // 2. Find smallest digit greater than pivot
        int j = len - 1;

        while (s[j] <= s[i]) {
            j--;
        }
    
        // 3. Swap
        swap(s[i], s[j]);

        // 4. Reverse suffix
        reverse(s.begin() + i + 1, s.end());

        // 5. Check 32-bit overflow
        long long ans = stoll(s);

        if (ans > INT_MAX)
            return -1;

        return (int)ans;
    }
};