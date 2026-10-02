class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> mp;

        // store frequency of t
        for(char ch : t) {
            mp[ch]++;
        }

        int left = 0;

        int count = t.size();

        int minLen = INT_MAX;

        int startIndex = 0;

        for(int right = 0; right < s.size(); right++) {

            // current character
            char ch = s[right];

            // useful character
            if(mp[ch] > 0)
                count--;

            mp[ch]--;

            // valid window
            while(count == 0) {

                // update answer
                if(right - left + 1 < minLen) {

                    minLen = right - left + 1;

                    startIndex = left;
                }

                // remove left character
                mp[s[left]]++;

                // character becomes needed again
                if(mp[s[left]] > 0)
                    count++;

                left++;
            }
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(startIndex, minLen);
    }
};

//-2
class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> freq(256, 0);

        for(char ch : t) {
            freq[ch]++;
        }

        int left = 0;

        int count = t.size();

        int minLen = INT_MAX;

        int startIndex = 0;

        for(int right = 0; right < s.size(); right++) {

            char ch = s[right];

            if(freq[ch] > 0)
                count--;

            freq[ch]--;

            while(count == 0) {

                if(right - left + 1 < minLen) {

                    minLen = right - left + 1;

                    startIndex = left;
                }

                freq[s[left]]++;

                if(freq[s[left]] > 0)
                    count++;

                left++;
            }
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(startIndex, minLen);
    }
};