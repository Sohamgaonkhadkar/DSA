class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int> mp;
        int preSum=0;
        mp[0]=1;
        for( int a: nums){
            preSum+=a;
            int rem = (preSum%k + k)%k;
            ans+=mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};