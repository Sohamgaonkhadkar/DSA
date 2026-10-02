class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        DisjointSet ds(n);

        unordered_map<string, int> mailToNode;

        // Union accounts having common emails
        for(int i = 0; i < n; i++) {

            for(int j = 1; j < accounts[i].size(); j++) {

                string mail = accounts[i][j];

                if(mailToNode.find(mail) == mailToNode.end()) {
                    mailToNode[mail] = i;
                }
                else {
                    ds.unionBySize(i, mailToNode[mail]);
                }
            }
        }

        // Store emails according to parent account
        vector<string> mergedMail[n];

        for(auto &it : mailToNode) {

            string mail = it.first;
            int node = it.second;

            int parent = ds.findUPar(node);

            mergedMail[parent].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++) {

            if(mergedMail[i].size() == 0)
                continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]); // name

            for(auto &mail : mergedMail[i]) {
                temp.push_back(mail);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};