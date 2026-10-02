#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr) {
    
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high) {

        int mid = (low + high) / 2;

        // left part sorted
        if (arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else { // right part sorted
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {5,6,0,1,2,3,4};
    cout << findMin(arr);
}

//2
while(low < high){
    int mid = (low + high) / 2;

    if(arr[mid] > arr[high])
        low = mid + 1;
    else
        high = mid;
}// can use this logic to find only min
int minIndex = low;              // pivot
int maxIndex = (minIndex - 1 + n) % n;