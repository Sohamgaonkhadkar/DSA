int upperBound(vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;   // move left
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
