class Solution {
public:
    int maxDepth(string s) {
        int depth = 0,maxi=0;

        for(char c : s)
        {
            if(c == '(')
            {
                
                depth++;
                maxi=max(maxi,depth);
            }
            else if (c==')')
            {
                depth--;
            }
        }

        return maxi;
    }
};