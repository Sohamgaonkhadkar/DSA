#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 2, 2, 4, 5};
    int x = 2;

    auto lb = lower_bound(v.begin(), v.end(), x);
    auto ub = upper_bound(v.begin(), v.end(), x);
    /*Why subtract iterators?

    Because STL functions return iterators, not indices.*/

    cout << "Lower Bound index: " << lb - v.begin() << endl;
    cout << "Upper Bound index: " << ub - v.begin() << endl;

    return 0;
}
//2
int lowerBound(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;   // move left
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
