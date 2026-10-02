class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        for (auto &x : nums)
    if (x % 2) x *= 2;

priority_queue<int> pq;

int mn = INT_MAX;

for (int x : nums) {
    pq.push(x);
    mn = min(mn, x);
}

int ans = INT_MAX;

while (true) {
    int mx = pq.top();
    pq.pop();

    ans = min(ans, mx - mn);

    if (mx % 2 == 1)
        break;

    mx /= 2;
    mn = min(mn, mx);

    pq.push(mx);
}

return ans;
    }
};