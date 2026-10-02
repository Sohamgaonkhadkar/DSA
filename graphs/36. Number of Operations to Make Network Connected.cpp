class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<int> vis(n, 0);

        for(auto &it : connections) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int components = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                components++;
                dfs(i, adj, vis);
            }
        }

        int edges = connections.size();
        if(edges < n - 1) return -1;
        return components - 1;
    }

private:
    void dfs(int node, vector<int> adj[], vector<int> &vis) {
        vis[node] = 1;
        for(auto &nbr : adj[node]) {
            if(!vis[nbr]) {
                dfs(nbr, adj, vis);
            }
        }
    }
};

//-2
class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;
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
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n - 1)
            return -1;

        DisjointSet ds(n);

        for(auto &it : connections) {
            ds.unionBySize(it[0], it[1]);
        }

        int components = 0;

        for(int i = 0; i < n; i++) {
            if(ds.findUPar(i) == i)
                components++;
        }

        return components - 1;
    }
};