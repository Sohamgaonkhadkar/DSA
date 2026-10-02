class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        for(int i = 0; i < n; i++) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }

        vector<pair<int,int>> intervals;

        for(int i = 0; i < n; i++) {

            if(i != first[s[i] - 'a'])
                continue;

            int l = i;
            int r = last[s[i] - 'a'];

            bool valid = true;

            for(int j = l; j <= r; j++) {

                int ch = s[j] - 'a';

                if(first[ch] < l) {
                    valid = false;
                    break;
                }

                r = max(r, last[ch]);
            }

            if(valid)
                intervals.push_back({l, r});
        }

        vector<string> ans;

        int prevEnd = -1;

        for(auto &[l, r] : intervals) {

            if(l > prevEnd) {

                ans.push_back(
                    s.substr(l, r - l + 1)
                );

                prevEnd = r;
            }
            else {

                if(r < prevEnd) {

                    ans.back() =
                        s.substr(l, r - l + 1);

                    prevEnd = r;
                }
            }
        }

        return ans;
    }
};