class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = 0, cand2 = 1; // initialize different
        int count1 = 0, count2 = 0;

        // Pass 1: Find candidates
        for (int num : nums) {
            if (num == cand1) count1++;
            else if (num == cand2) count2++;
            else if (count1 == 0) {
                cand1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                cand2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Pass 2: Verify
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == cand1) count1++;
            else if (num == cand2) count2++;
        }

        vector<int> ans;
        int n = nums.size();
        if (count1 > n / 3) ans.push_back(cand1);
        if (count2 > n / 3) ans.push_back(cand2);

        return ans;
    }
};
