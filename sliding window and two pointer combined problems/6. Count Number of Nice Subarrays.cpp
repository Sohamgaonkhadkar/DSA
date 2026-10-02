class Solution {
public:
    bool isOdd(int num) {
        return (num & 1);
    }
    int numberOfSubarrays(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;

        mp[0] = 1;

        int sum = 0;
        int ans = 0;

        for(int num : nums) {

            if(isOdd(num)) {
                sum++;
            }

            if(mp.count(sum - goal)) {
                ans += mp[sum - goal];
            }

            mp[sum]++;
        }

        return ans;
    }
};
//-2
class Solution {
public:

    int atMost(vector<int>& nums, int k) {

        if(k < 0)
            return 0;

        int left = 0;
        int count = 0;
        int oddCount = 0;

        for(int right = 0; right < nums.size(); right++) {

            // odd number
            if(nums[right] & 1)
                oddCount++;

            // shrink window
            while(oddCount > k) {

                if(nums[left] & 1)
                    oddCount--;

                left++;
            }

            // all valid subarrays ending at right
            count += (right - left + 1);
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        return atMost(nums, k) - atMost(nums, k - 1);
    }
};