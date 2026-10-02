class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(!g.empty() && !s.empty()){
            if(g.back()<=s.back()){
                count++;
                g.pop_back();
                s.pop_back();
            }
            else{
                g.pop_back();
            }
        }
        return count;
    }
};
//-2
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = g.size() - 1; // child pointer
        int j = s.size() - 1; // cookie pointer

        int count = 0;

        while(i >= 0 && j >= 0) {

            // cookie can satisfy child
            if(s[j] >= g[i]) {
                count++;
                i--;
                j--;
            }
            else {
                // current child cannot be satisfied
                i--;
            }
        }

        return count;
    }
};