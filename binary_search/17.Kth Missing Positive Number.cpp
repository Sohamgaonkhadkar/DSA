class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(), i = 1, maxi = 0, m = 0, flag = 0;

        for(int j = 0; j < n; j++){
            maxi = max(maxi, arr[j]);
        }

        while(1){
            if(i <= maxi){
                flag = 0;

                for(int j = 0; j < n; j++){
                    if(i == arr[j]){
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0){
                    m++;
                    if(m == k){
                        return i;
                    }
                }
            }
            else{
                m++;
                if(m == k){
                    return i;
                }
            }

            i++;
        }
    }
};
//optimal
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int missing = arr[mid] - (mid + 1);

            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low + k;
    }
};