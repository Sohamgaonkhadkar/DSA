class Solution {
public:

    void dfs1(int node,
              vector<int> adj[],
              vector<int>& vis,
              stack<int>& st) {

        vis[node] = 1;

        for(auto it : adj[node]) {
            if(!vis[it])
                dfs1(it, adj, vis, st);
        }

        st.push(node);
    }

    void dfs2(int node,
              vector<int> adjT[],
              vector<int>& vis) {

        vis[node] = 1;

        for(auto it : adjT[node]) {
            if(!vis[it])
                dfs2(it, adjT, vis);
        }
    }

    int kosaraju(int V, vector<vector<int>>& edges) {

        vector<int> adj[V];

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        stack<int> st;
        vector<int> vis(V, 0);

        // Step 1
        for(int i = 0; i < V; i++) {
            if(!vis[i])
                dfs1(i, adj, vis, st);
        }

        // Step 2
        vector<int> adjT[V];

        for(int i = 0; i < V; i++) {
            vis[i] = 0;

            for(auto it : adj[i]) {
                adjT[it].push_back(i);
            }
        }

        // Step 3
        int scc = 0;

        while(!st.empty()) {

            int node = st.top();
            st.pop();

            if(!vis[node]) {

                scc++;

                dfs2(node, adjT, vis);
            }
        }

        return scc;
    }
};