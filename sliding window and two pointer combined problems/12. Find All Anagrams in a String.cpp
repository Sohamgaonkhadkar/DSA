class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if(p.size() > s.size())
            return ans;

        vector<int> freqP(26,0);
        vector<int> freqS(26,0);

        // frequency of p
        for(char c : p)
            freqP[c-'a']++;

        int k = p.size();

        // first window
        for(int i=0; i<k; i++)
            freqS[s[i]-'a']++;

        if(freqS == freqP)
            ans.push_back(0);


        // sliding window
        for(int i=k; i<s.size(); i++)
        {
            // add new character
            freqS[s[i]-'a']++;

            // remove old character
            freqS[s[i-k]-'a']--;

            if(freqS == freqP)
                ans.push_back(i-k+1);
        }

        return ans;
    }
};