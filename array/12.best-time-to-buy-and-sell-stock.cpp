class Solution {
public:
    int maxProfit(vector<int>&a) {
        int mini=a[0],profit=0,cost;
        for(int i=1;i<a.size();i++){
            cost=a[i]-mini;
            profit=max(profit,cost);
            mini=min(mini,a[i]);

        }
        return profit;
        
    }
};