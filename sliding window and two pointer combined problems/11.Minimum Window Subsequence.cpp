class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.size();
        int m = t.size();

        int minLen = INT_MAX;
        int start = -1;

        int i = 0;

        while(i < n) {

            int j = 0;

            // forward match
            while(i < n) {

                if(s[i] == t[j])
                    j++;

                if(j == m)
                    break;

                i++;
            }

            // no subsequence found
            if(i == n)
                break;

            // end of valid window
            int end = i;

            // move backward to minimize
            j = m - 1;

            while(i >= 0) {

                if(s[i] == t[j])
                    j--;

                if(j < 0)
                    break;

                i--;
            }

            // start of minimum valid window
            int windowStart = i;

            // update answer
            if(end - windowStart + 1 < minLen) {

                minLen = end - windowStart + 1;

                start = windowStart;
            }

            // continue searching
            i = windowStart + 1;
        }

        if(start == -1)
            return "";

        return s.substr(start, minLen);
    }
};