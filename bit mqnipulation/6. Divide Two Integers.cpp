class Solution {
public:

    int divide(int dividend, int divisor) {

        // Overflow case
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine sign
        bool negative =
            (dividend < 0) ^ (divisor < 0);

        // Convert to positive long long
        long long a = abs((long long) dividend);
        long long b = abs((long long) divisor);

        long long ans = 0;

        while(a >= b) {

            long long temp = b;
            long long multiple = 1;

            // Find maximum shifted divisor
            while((temp << 1) <= a) {

                temp <<= 1;
                multiple <<= 1;
            }

            // Subtract
            a -= temp;

            // Add quotient contribution
            ans += multiple;
        }

        // Apply sign
        if(negative)
            ans = -ans;

        return (int) ans;
    }
}; 