class Solution {
public:
    int sum_1(string s) {
        vector<int> freq(26, 0);

        for(char c : s) {
            freq[c - 'a']++;
        }

        int maxFreq = 0;
        int minFreq = INT_MAX;

        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                maxFreq = max(maxFreq, freq[i]);
                minFreq = min(minFreq, freq[i]);
            }
        }

        return maxFreq - minFreq;
    }
    int beautySum(string s) {
        int n = s.size(),sum=0;

        for(int i = 0; i < n; i++) {
                string temp = "";
                for(int j = i; j < n; j++) {
                    temp += s[j];   // build incrementally
                    sum+=sum_1(temp);
                }
            }
            return sum;
        }    
};

//-2
class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), sum = 0;

        for(int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int maxFreq = 0, minFreq = INT_MAX;

                for(int k = 0; k < 26; k++) {
                    if(freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }

                sum += (maxFreq - minFreq);
            }
        }
        return sum;
    }
};