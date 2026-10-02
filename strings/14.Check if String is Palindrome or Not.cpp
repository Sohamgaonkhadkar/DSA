class Solution {
public:
    bool isPalindrome(string s) {
        string a="";
        for(char c : s) {
        if(isalnum(c)) {   
            a += tolower(c);
        }
        }
        int i=0,j=a.size()-1;
        while(i<=j){
            if(a[i]!=a[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;


    }
};

//-2
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while(i < j) {

            // skip non-alphanumeric from left
            while(i < j && !isalnum(s[i])) i++;

            // skip non-alphanumeric from right
            while(i < j && !isalnum(s[j])) j--;

            // compare (case insensitive)
            if(tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};