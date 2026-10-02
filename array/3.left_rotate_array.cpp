class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = nums.size() - k % nums.size();
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(),nums.end());
    }
};

class Solution {
public:
    
    void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;

    vector<int> temp(n);
    for (int i =  0; i < n; i++) {
        temp[(i + k) % n] = nums[i];
    }

    nums = temp;
}
};