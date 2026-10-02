class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();

        int sum = 1;
        int i = 1;

        while (i < n) {

            // Equal ratings
            if (ratings[i] == ratings[i - 1]) {
                sum += 1;
                i++;
                continue;
            }

            // Increasing slope
            int peak = 1;

            while (i < n && ratings[i] > ratings[i - 1]) {

                peak++;
                sum += peak;
                i++;
            }

            // Decreasing slope
            int down = 1;

            while (i < n && ratings[i] < ratings[i - 1]) {

                sum += down;
                down++;
                i++;
            }

            // Peak counted twice correction
            if (down > peak) {
                sum += (down - peak);
            }
        }

        return sum;
    }
};