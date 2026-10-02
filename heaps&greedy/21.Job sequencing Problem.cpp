class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] > b[2];
    }

    vector<int> JobScheduling(vector<vector<int>>& Jobs) {

        sort(Jobs.begin(), Jobs.end(), cmp);

        int maxDeadline = 0;

        for (auto &job : Jobs) {
            maxDeadline = max(maxDeadline, job[1]);
        }

        vector<int> slot(maxDeadline + 1, -1);

        int countJobs = 0;
        int totalProfit = 0;

        for (auto &job : Jobs) {

            int id = job[0];
            int deadline = job[1];
            int profit = job[2];

            for (int j = deadline; j >= 1; j--) {

                if (slot[j] == -1) {

                    slot[j] = id;

                    countJobs++;
                    totalProfit += profit;

                    break;
                }
            }
        }

        return {countJobs, totalProfit};
    }
};