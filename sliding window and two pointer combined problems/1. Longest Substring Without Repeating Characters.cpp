class Solution {
public:
    bool allUnique(string s) {

    unordered_set<char> st;

    for(char ch : s) {

        if(st.count(ch))
            return false;

        st.insert(ch);
    }

    return true;
}
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_set<char> st;
        int ans=0;
        int left=0,right=0;
        while(right<n){
            if(allUnique(s.substr(left, right - left + 1))){
                ans = max(ans, right - left + 1);
                right++;
            }
            else {
                
                left++;
            }
          
        }
        return ans;
    }
};

//-2

class Solution {
public:

    int lengthOfLongestSubstring(string s) {

        unordered_set<char> st;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < s.size(); right++) {

            while(st.count(s[right])) {

                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
//-3
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> lastIndex(256, -1);

        int left = 0;
        int ans = 0;

        for(int right = 0; right < s.size(); right++) {

            if(lastIndex[s[right]] >= left) {

                left = lastIndex[s[right]] + 1;
            }

            lastIndex[s[right]] = right;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};