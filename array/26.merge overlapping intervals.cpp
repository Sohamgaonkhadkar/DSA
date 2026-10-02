class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return intervals;

        sort(intervals.begin(), intervals.end());

        int idx = 0;  // index of last merged interval

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= intervals[idx][1]) {
                // overlap → merge
                intervals[idx][1] = max(intervals[idx][1], intervals[i][1]);
            } else {
                // no overlap → move forward
                idx++;
                intervals[idx] = intervals[i];
            }
        }

        intervals.resize(idx + 1);
        return intervals;
    }
};

//
sort(arr.begin(), arr.end());
vector<vector<int>> ans;

for (int i = 0; i < n; i++) {
    if (ans.empty() || arr[i][0] > ans.back()[1])
        ans.push_back(arr[i]);
    else
        ans.back()[1] = max(ans.back()[1], arr[i][1]);
}

