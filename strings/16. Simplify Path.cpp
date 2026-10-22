class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string part;

        while (getline(ss, part, '/')) {
            if (part == "" || part == ".")
                continue;

            if (part == "..") {
                if (!st.empty())
                    st.pop();
            }
            else {
                st.push(part);
            }
        }

        vector<string> dirs;

        while (!st.empty()) {
            dirs.push_back(st.top());
            st.pop();
        }

        string ans = "";

        for (int i = dirs.size() - 1; i >= 0; i--) {
            ans += "/" + dirs[i];
        }

        return ans.empty() ? "/" : ans;
    }
};