class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int n = arr.size();

        int i = 0;
        int j = 0;

        int platforms = 0;
        int ans = 0;

        while(i < n && j < n) {

            // Need new platform
            // '=' because same platform can't be reused instantly
            if(arr[i] <= dep[j]) {
                platforms++;
                ans = max(ans, platforms);
                i++;
            }
            else {
                // One train departed
                platforms--;
                j++;
            }
        }

        return ans;
    }
};