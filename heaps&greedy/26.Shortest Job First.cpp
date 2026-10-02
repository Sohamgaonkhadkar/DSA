class Solution {
  public:
    long long solve(vector<int>& bt) {
        
        sort(bt.begin(), bt.end());
        
        long long waitingTime = 0;
        long long currentTime = 0;
        
        for(int i = 0; i < bt.size(); i++) {
            
            waitingTime += currentTime;
            
            currentTime += bt[i];
        }
        
        return waitingTime / bt.size();
    }
};