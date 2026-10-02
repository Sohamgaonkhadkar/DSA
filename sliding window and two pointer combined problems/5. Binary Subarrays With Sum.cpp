class Solution {
public:

    int atMost(vector<int>& nums, int goal) {

        if(goal < 0)
            return 0;

        int left = 0;
        int sum = 0;
        int count = 0;

        for(int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            while(sum > goal) {

                sum -= nums[left];
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return atMost(nums, goal)
             - atMost(nums, goal - 1);
    }
};
//-2
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        unordered_map<int, int> mp;

        mp[0] = 1;

        int sum = 0;
        int ans = 0;

        for(int num : nums) {

            sum += num;

            if(mp.count(sum - goal)) {
                ans += mp[sum - goal];
            }

            mp[sum]++;
        }

        return ans;
    }
};