class Solution {
public:

    bool valid(string s){

        for(int i=0; i<s.size()-1; i++){

            if(s[i]=='1' && s[i+1]=='1')
                return false;
        }

        return true;
    }

    void generate(int n, string s, vector<string>& ans){

        if(s.size() == n){

            if(valid(s))
                ans.push_back(s);

            return;
        }

        generate(n, s + '0', ans);
        generate(n, s + '1', ans);
    }

    vector<string> generateBinaryStrings(int n) {

        vector<string> ans;

        generate(n, "", ans);

        return ans;
    }
};

//2-
class Solution {
public:

    void solve(int n, string s, vector<string>& ans){

        // Base case
        if(s.size() == n){
            ans.push_back(s);
            return;
        }

        // Always can place 0
        solve(n, s + '0', ans);

        // Place 1 only if previous not 1
        if(s.empty() || s.back() != '1'){
            solve(n, s + '1', ans);
        }
    }

    vector<string> generateBinaryStrings(int n) {

        vector<string> ans;

        solve(n, "", ans);

        return ans;
    }
};
