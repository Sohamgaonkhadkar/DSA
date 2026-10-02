class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        
        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') i++;
        
        // 2. Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        
        // 3. Convert digits
        long ans = 0;   // long to handle overflow
        
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // 4. Handle overflow BEFORE adding
            if (ans > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            ans = ans * 10 + digit;
            i++;
        }
        
        return sign * ans;
    }
};