#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();

    for(int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }

    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {

    int totalH = 0;
    int n = v.size();

    for(int i = 0; i < n; i++) {
        totalH += ceil((double)v[i] / (double)hourly);
    }

    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {

    int low = 1;
    int high = findMax(v);

    while(low <= high) {

        int mid = (low + high) / 2;

        int totalH = calculateTotalHours(v, mid);

        if(totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return low;
}
//
class Solution {
public:

    bool canEat(vector<int>& piles, int h, int speed) {

        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + speed - 1) / speed;
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (canEat(piles, h, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};