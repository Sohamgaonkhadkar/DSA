class Solution {
public:
    int kDistinctChar(string& s, int k) {
        
        unordered_map<char, int> mp;

        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < s.size(); right++) {

            
            mp[s[right]]++;

            
            while(mp.size() > k) {

                mp[s[left]]--;

                // remove if frequency becomes 0
                if(mp[s[left]] == 0)
                    mp.erase(s[left]);

                left++;
            }

            // valid window
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;//your code goes here
    }
};

//2
class Solution {
public:
    int kDistinctChar(string& s, int k) {

        vector<int> freq(26, 0);

        int left = 0;
        int distinct = 0;
        int maxLen = 0;

        for(int right = 0; right < s.size(); right++) {

            if(freq[s[right] - 'a'] == 0)
                distinct++;

            freq[s[right] - 'a']++;

            while(distinct > k) {

                freq[s[left] - 'a']--;

                if(freq[s[left] - 'a'] == 0)
                    distinct--;

                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};