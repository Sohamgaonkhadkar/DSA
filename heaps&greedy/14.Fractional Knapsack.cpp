class Solution {
public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        int n=val.size();
        vector<pair<double,int>> ratio;
        for(int i=0;i<n;i++){
            ratio.push_back({(double)val[i]/wt[i],i});
        }
        sort(ratio.rbegin(),ratio.rend());
        double totalValue=0.0;
        for(int i=0;i<n;i++){
            int idx=ratio[i].second;
            double r=ratio[i].first;
            if(wt[idx]<=capacity){
                totalValue+=val[idx];
                capacity-=wt[idx];
            }
            else{
                totalValue+=r*capacity;
                break;
            }
        }
        return totalValue;
    }
};