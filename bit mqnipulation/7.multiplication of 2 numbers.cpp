class Solution {
public:

    int multiply(int a, int b) {

        int ans = 0;

        while(b > 0) {

            // If last bit of b is 1
            if(b & 1) {
                ans += a;
            }
            
            // Double a
            a = a << 1;

            // Move to next bit
            b = b >> 1;
        }

        return ans;
    }
};
