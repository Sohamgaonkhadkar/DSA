 #include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x, int m) {
    int low = 0, high = m - 1;
    int ans = m;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } 
        else {
            low = mid + 1; // look for right
        }
    }

    return ans;
}
[1,2,5,6]
int countSmallEqual(vector<vector<int>> &matrix, int n, int m, int x) {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        cnt += upperBound(matrix[i], x, m);
    }

    return cnt;
}

int median(vector<vector<int>> &matrix, int n, int m) {

    int low = INT_MAX;
    int high = INT_MIN;

    n = matrix.size();
    m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }

    int req = (n * m) / 2;

    while (low <= high) {
        int mid = (low + high) / 2;

        int smallEqual = countSmallEqual(matrix, n, m, mid);

        if (smallEqual <= req)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}
