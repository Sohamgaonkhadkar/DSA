class Solution {
public:

    vector<string> ans;

    void solve(string num,
               int target,
               int idx,
               long currValue,
               long prev,
               string path) {

        // Base case
        if(idx == num.size()) {

            if(currValue == target) {
                ans.push_back(path);
            }

            return;
        }

        string temp = "";

        long number = 0;

        for(int i = idx; i < num.size(); i++) {

            // Skip leading zeros
            if(i > idx && num[idx] == '0')
                break;

            temp += num[i];

            number = number * 10 + (num[i] - '0');

            // First number
            if(idx == 0) {

                solve(num,
                      target,
                      i + 1,
                      number,
                      number,
                      temp);
            }

            else {

                // +
                solve(num,
                      target,
                      i + 1,
                      currValue + number,
                      number,
                      path + "+" + temp);

                // -
                solve(num,
                      target,
                      i + 1,
                      currValue - number,
                      -number,
                      path + "-" + temp);

                // *
                solve(num,
                      target,
                      i + 1,
                      currValue - prev + prev * number,
                      prev * number,
                      path + "*" + temp);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        solve(num,
              target,
              0,
              0,
              0,
              "");

        return ans;
    }
};