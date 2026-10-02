#include <bits/stdc++.h>
using namespace std;

int subarraysWithSumK(vector<int> a, int k) {
    int xr = 0;
    int cnt = 0;
    unordered_map<int, int> mpp;

    mpp[0] = 1;   // very important

    for (int i = 0; i < a.size(); i++) {
        xr = xr ^ a[i];

        int x = xr ^ k;

        cnt += mpp[x];

        mpp[x]++;
    }

    return cnt;
}
