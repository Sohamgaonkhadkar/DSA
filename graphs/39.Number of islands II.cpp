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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {

        DisjointSet ds(n * m);

        vector<vector<int>> vis(n, vector<int>(m, 0));

        vector<int> ans;

        int cnt = 0;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(auto &it : operators) {

            int row = it[0];
            int col = it[1];

            // already land
            if(vis[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }

            vis[row][col] = 1;
            cnt++;

            for(int k = 0; k < 4; k++) {

                int nrow = row + dr[k];
                int ncol = col + dc[k];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   vis[nrow][ncol] == 1) {

                    int nodeNo = row * m + col;
                    int adjNodeNo = nrow * m + ncol;

                    if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)) {

                        cnt--;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};