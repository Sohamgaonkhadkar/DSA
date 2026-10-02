class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // count frequency
        for (char c : s) freq[c]++;

        // buckets: index = frequency
        vector<string> bucket(s.size() + 1);

        for (auto &p : freq) {
            bucket[p.second] += string(p.second, p.first);
        }

        // build result (high → low frequency)
        string result;
        for (int i = s.size(); i >= 1; i--) {
            result += bucket[i];
        }

        return result;
    }
};