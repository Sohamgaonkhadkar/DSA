 int n = nums.size();
    vector<int> ans(n);

    int pos = 0, neg = 1;

    for (int x : nums) {
        if (x > 0) {
            ans[pos] = x;
            pos += 2;
        } else {
            ans[neg] = x;
            neg += 2;
        }
    }
    return ans;