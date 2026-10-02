class Solution {
public:
    long solve(string &s, int i, long ans, int sign) {

        // Base case
        if(i >= s.size() || !isdigit(s[i]))
            return sign * ans;

        int digit = s[i] - '0';

        // Overflow check
        if(ans > (INT_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        ans = ans * 10 + digit;

        return solve(s, i + 1, ans, sign);
    }

    int myAtoi(string s) {

        int i = 0;
        int n = s.size();

        // Skip spaces
        while(i < n && s[i] == ' ')
            i++;

        // Handle sign
        int sign = 1;

        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-')
                sign = -1;

            i++;
        }

        return solve(s, i, 0, sign);
    }
};