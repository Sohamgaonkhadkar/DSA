class Solution {
public:

    long long func(int mid, int n) {

        long long ans = 1;

        while(n > 0) {

            if(n % 2 == 1) {
                ans = ans * mid;
                n = n - 1;
            }
            else {
                mid = mid * mid;
                n = n / 2;
            }

        }

        return ans;
    }

    int NthRoot(int N, int M) {

        int low = 1, high = M;

        while(low <= high) {

            int mid = (low + high) / 2;

            long long val = func(mid, N);

            if(val == M)
                return mid;

            else if(val < M)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }
};