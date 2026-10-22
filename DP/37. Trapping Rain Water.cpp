class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prev_max(n);
        vector<int> next_max(n);
        int maxi = height[0];
        for (int i= 0 ; i<n ; i++){
            maxi= max(maxi, height[i]);
            prev_max[i]= maxi;
        }
        maxi=height[n-1];
        for (int i= n-1 ; i>=0 ; i--){
            maxi= max(maxi, height[i]);
            next_max[i]= maxi;
        }
        int ans=0;
        int mini;
        for (int i= n-1 ; i>=0 ; i--){
            mini= min(prev_max[i],next_max[i]);
            if ( height[i]>mini){
                continue;
            }
            else{
                ans+= mini-height[i];
            }
        }
        return ans;
    }
};