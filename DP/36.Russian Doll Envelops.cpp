class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end());
        vector<int> dp(n,1);
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

//-2
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b) {
            if (a[0] == b[0])
                return a[1] > b[1];

            return a[0] < b[0];
        });

        vector<int> temp;
        temp.push_back(envelopes[0][1]);

        for (int i = 1; i < envelopes.size(); i++) {

            int h = envelopes[i][1];

            if (h > temp.back()) {
                temp.push_back(h);
            }
            else {
                int ind = lower_bound(temp.begin(), temp.end(), h)
                          - temp.begin();

                temp[ind] = h;
            }
        }

        return temp.size();
    }
};
