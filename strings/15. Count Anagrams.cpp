class Solution {
public:

    long long factorial(int n) {
        long long ans = 1;
        for(int i = 1; i <= n; i++)
            ans *= i;
        return ans;
    }

    long long ans = 1;

    void permutation(unordered_map<char, int>& mp) {
        long long fact = 0;
        long long den = 1;

        for(auto it : mp) {
            fact += it.second;
            den *= factorial(it.second);
        }

        ans *= factorial(fact) / den;
    }

    int countAnagrams(string s) {
        unordered_map<char, int> mp;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == ' ') {
                permutation(mp);
                mp.clear();
            }

            else {
                mp[s[i]]++;
            }
        }

        permutation(mp);

        return ans;
    }
};
//-2
class Solution {
public:

    const long long MOD = 1e9 + 7;
    vector<long long> dp;

    // DP for factorial
    void factorial(int n) {
        dp.resize(n + 1);

        dp[0] = 1;

        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] * i % MOD;
        }
    }

    // a^b % MOD
    long long power(long long a, long long b) {
        long long ans = 1;

        while(b > 0) {

            if(b % 2 == 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b /= 2;
        }

        return ans;
    }

    long long ans = 1;

    void permutation(unordered_map<char, int>& mp) {

        long long fact = 0;
        long long den = 1;

        for(auto it : mp) {

            fact += it.second;

            den = den * dp[it.second] % MOD;
        }

        // fact! / den
        // Division under MOD => multiply by modular inverse
        long long ways = dp[fact];

        ways = ways * power(den, MOD - 2) % MOD;

        ans = ans * ways % MOD;
    }

    int countAnagrams(string s) {

        // Precompute factorials
        factorial(s.size());

        unordered_map<char, int> mp;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == ' ') {

                permutation(mp);

                mp.clear();
            }
            else {
                mp[s[i]]++;
            }
        }

        // Last word
        permutation(mp);

        return ans;
    }
};