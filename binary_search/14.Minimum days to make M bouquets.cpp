class Solution {
public:

    bool possible(vector<int>& b, int day, int m, int k){
        int n = b.size();
        int count = 0, no_of_B = 0;

        for(int i = 0; i < n; i++){
            if(b[i] <= day){
                count++;
            }
            else{
                no_of_B += count / k;
                count = 0;
            }
        }

        no_of_B += count / k;

        return no_of_B >= m;
    }

    int minDays(vector<int>& b, int m, int k) {
        int n = b.size();

        if((long long)m * k > n) return -1;

        int mini = INT_MAX, maxi = INT_MIN;

        for(int i = 0; i < n; i++){
            mini = min(mini, b[i]);
            maxi = max(maxi, b[i]);
        }

        int low = mini, high = maxi;

        while(low <= high){
            int mid = (low + high) / 2;

            if(possible(b, mid, m, k)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};