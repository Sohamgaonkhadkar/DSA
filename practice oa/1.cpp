#include <bits/stdc++.h>
using namespace std;

long long maximumScore(vector<int> cell) {

    int n = cell.size();

    // Generate all prime jumps ending with 3
    vector<int> jumps;

    for (int x = 3; x < n; x += 10) {

        bool prime = true;

        for (int d = 2; d * d <= x; d++) {
            if (x % d == 0) {
                prime = false;
                break;
            }
        }
        if (prime)
            jumps.push_back(x);
    }

    vector<long long> dp(n, LLONG_MIN);

    dp[0] = 0;

    for (int i = 1; i < n; i++) {

        // Move one step
        if (dp[i - 1] != LLONG_MIN)
            dp[i] = max(dp[i], dp[i - 1] + cell[i]);

        // Prime jumps
        for (int p : jumps) {

            if (p > i)
                break;

            if (dp[i - p] != LLONG_MIN)
                dp[i] = max(dp[i], dp[i - p] + cell[i]);
        }
    }

    return dp[n - 1];
}

int main() {

    vector<int> cell = {0, 10, -20, -30, 50};

    cout << maximumScore(cell);

    return 0;
}