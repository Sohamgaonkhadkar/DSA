class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I',1}, {'V',5}, {'X',10},
            {'L',50}, {'C',100},
            {'D',500}, {'M',1000}
        };

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i+1 < s.size() && mp[s[i]] < mp[s[i+1]])
                ans -= mp[s[i]];
            else
                ans += mp[s[i]];
        }

        return ans;
    }
};
//-2
class Solution {
public:
    int getVal(char c) {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        return 1000; // M
    }

    int romanToInt(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int val = getVal(s[i]);

            if (i + 1 < s.size() && val < getVal(s[i + 1]))
                ans -= val;
            else
                ans += val;
        }

        return ans;
    }
};