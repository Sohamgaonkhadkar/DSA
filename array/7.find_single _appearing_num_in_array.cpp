int singleNumber(vector<int>& nums) {
    map<int, int> mp;

    // Count frequency
    for (int x : nums) {
        mp[x]++;
    }

    // Find the element that appears once
    for (auto it : mp) {
        if (it.second == 1) {
            return it.first;
        }
    }
    return -1;
}
//2
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int x : nums) {
        ans ^= x;
    }
    return ans;
}
/*ans = 0
ans = 0 ^ 4 = 4
ans = 4 ^ 1 = 5
ans = 5 ^ 2 = 7
ans = 7 ^ 1 = 6
ans = 6 ^ 2 = 4
*/