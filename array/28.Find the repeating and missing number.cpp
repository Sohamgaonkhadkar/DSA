class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> arr) {
        unordered_map<int, int> freq;
        int n = arr.size();

        // build frequency map
        for (int x : arr) {
            freq[x]++;
        }

        int repeating = -1, missing = -1;

        // find repeating and missing
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2)
                repeating = i;
            else if (freq[i] == 0)
                missing = i;
        }

        return {repeating, missing};
    }
};
//optimal -maths
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> arr) {
        long long n = arr.size();

        long long S  = n * (n + 1) / 2;
        long long S2 = n * (n + 1) * (2*n + 1) / 6;

        long long s = 0, s2 = 0;
        for (int x : arr) {
            s  += x;
            s2 += 1LL * x * x;
        }

        long long diff = s - S;            // A - B
        long long sum  = (s2 - S2) / diff; // A + B

        long long A = (diff + sum) / 2;    // repeating
        long long B = sum - A;             // missing

        return {(int)A, (int)B};
    }
};
