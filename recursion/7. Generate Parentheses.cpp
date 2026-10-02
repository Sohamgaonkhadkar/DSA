class Solution {
public:
    void generate(int n, string s, vector<string>& ans){

        if(s.size() == 2*n){

            if(valid(s))
                ans.push_back(s);

            return;
        }

        generate(n, s + '(', ans);
        generate(n, s + ')', ans);
    }

    bool valid(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else {
                count--;
                if (count < 0) {
                    return false;
                }
            }
        }
        return count == 0;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, "", ans);

        return ans;
    }
};

//-2
class Solution {
public:

    void solve(int open, int close, int n,
               string s, vector<string>& ans){

        // Valid string formed
        if(s.size() == 2 * n){
            ans.push_back(s);
            return;
        }

        // Add '('
        if(open < n){
            solve(open + 1, close, n, s + '(', ans);
        }

        // Add ')'
        if(close < open){
            solve(open, close + 1, n, s + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        solve(0, 0, n, "", ans);

        return ans;
    }
};
