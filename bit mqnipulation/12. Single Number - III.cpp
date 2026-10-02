class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int xr = 0;

        for(int num : nums) {
            xr ^= num;
        }

        // Rightmost set bit
        int bit = xr & (-xr);

        int a = 0;
        int b = 0;

        for(int num : nums) {

            if(num & bit)
                a ^= num;
            else
                b ^= num;
        }

        return {a, b};
    }
};