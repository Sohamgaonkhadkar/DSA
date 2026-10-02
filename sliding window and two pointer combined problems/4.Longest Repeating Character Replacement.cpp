class Solution {
public:
    int characterReplacement(string s, int k) {

        vector<int> freq(26, 0);

        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for(int right = 0; right < s.size(); right++) {

            // increase frequency
            freq[s[right] - 'A']++;

            // store maximum frequency character count
            maxFreq = max(
                maxFreq,
                freq[s[right] - 'A']
            );

            int windowLen = right - left + 1;

            // invalid window
            while(windowLen - maxFreq > k) {

                freq[s[left] - 'A']--;

                left++;

                windowLen = right - left + 1;
            }

            // valid window
            maxLen = max(maxLen, windowLen);
        }

        return maxLen;
    }
};