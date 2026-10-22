class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        unordered_map<char, int> need, window;

        for (char c : s1)
            need[c]++;

        int left = 0;

        for (int right = 0; right < s2.size(); right++) {
            window[s2[right]]++;

            // Keep window size equal to s1.size()
            if (right - left + 1 > s1.size()) {
                char c = s2[left];

                window[c]--;
                if (window[c] == 0)
                    window.erase(c);

                left++;
            }

            // Check when window size is correct
            if (right - left + 1 == s1.size() &&
                window == need) {
                return true;
            }
        }

        return false;
    }
};