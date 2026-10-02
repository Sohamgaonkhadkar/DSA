#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k) {
            first = mid;       // store answer
            high = mid - 1;    // move left
        }
        else if (arr[mid] < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return first;
}
