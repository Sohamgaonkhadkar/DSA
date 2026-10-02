#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1; // s -> t
        unordered_map<char, char> mp2; // t -> s

        for(int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // check mapping s -> t
            if(mp1.count(c1)) {
                if(mp1[c1] != c2)
                    return false;
            } else {
                mp1[c1] = c2;
            }

            // check reverse mapping t -> s
            if(mp2.count(c2)) {
                if(mp2[c2] != c1)
                    return false;
            } else {
                mp2[c2] = c1;
            }
        }

        return true;
    }
};
//-2
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}; // s → t mapping
        int m2[256] = {0}; // t → s mapping

        for(int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // if both are not mapped yet
            if(m1[c1] == 0 && m2[c2] == 0) {
                m1[c1] = c2;
                m2[c2] = c1;
            }
            else {
                // check consistency
                if(m1[c1] != c2 || m2[c2] != c1)
                    return false;
            }
        }

        return true;
    }
};