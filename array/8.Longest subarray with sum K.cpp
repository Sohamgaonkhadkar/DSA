int longestSubarrayWithSumK(vector<int> a, long long k) {
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;

    for(int i = 0; i < a.size(); i++) {
        sum += a[i];

        if(sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }/*f rem exists in the map
→ returns an iterator pointing to that (key, value) pair

If rem does NOT exist
→ returns preSumMap.end()*/

        if(preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}


// 2 pointer approach
int longestSubarrayWithSumK(vector<int> a, long long k) {
   int left=0,right=0;
   long long sum=a[0];
   int maxlen = 0;
   int n =a.size();
   while (right < n){
    while (left <= right && sum>k) {
        sum-=a[left];
        left++;
    }
    if(sum==k){
        maxlen = max(maxlen, right-left+1);
    }
    right++;
    if(right<n) sum+=a[right];
   }
   return maxlen;
}
//
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {

        unordered_map<long long,int> mp;

        long long sum = 0;
        int maxi = 0;

        for(int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            if(sum == k)
                maxi = max(maxi, i + 1);

            if(mp.find(sum - k) != mp.end()) {
                maxi = max(maxi, i - mp[sum - k]);
            }

            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }

        return maxi;
    }
}; 

+