//-1
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string prefix = strs[0];

        for(int i = 1; i < strs.size(); i++) {

            while(strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
            }

        }

        return prefix;
    }
};
//-2Sorting arranges words lexicographically (dictionary order).
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs.back();

        string ans = "";

        for(int i = 0; i < first.size(); i++) {

            if(first[i] == last[i])
                ans += first[i];
            else
                break;
        }

        return ans;
    }
};