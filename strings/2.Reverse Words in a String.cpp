//-1
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = s.size() - 1;

        while(i >= 0)
        {
            while(i >= 0 && s[i] == ' ') i--;   // skip spaces

            if(i < 0) break;

            int j = i;

            while(i >= 0 && s[i] != ' ') i--;   // find word start

            if(ans.size() > 0) ans += " ";

            ans += s.substr(i + 1, j - i);
        }

        return ans;
    }
};
//-2
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        // remove extra spaces
        int i = 0, j = 0, n = s.size();
        while (j < n) {
            while (j < n && s[j] == ' ') j++;   // skip spaces
            while (j < n && s[j] != ' ') s[i++] = s[j++]; // copy word
            while (j < n && s[j] == ' ') j++; 
            if (j < n) s[i++] = ' ';
        }
        s.resize(i);

        // reverse entire string
        reverse(s.begin(), s.end());

        // reverse each word
        int start = 0;
        for (int end = 0; end <= s.size(); end++) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }
};