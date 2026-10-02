class Solution {
public:
    bool checkValidString(string s) {

        int mini = 0;
        int maxi = 0;

        for(char ch : s) {

            if(ch == '(') {

                mini++;
                maxi++;
            }

            else if(ch == ')') {

                mini--;
                maxi--;
            }

            else { // '*'

                mini--;  
                maxi++;  
            }

            if(maxi < 0) {
                return false;
            }

            mini = max(mini, 0);
        }

        return mini == 0;
    }
};