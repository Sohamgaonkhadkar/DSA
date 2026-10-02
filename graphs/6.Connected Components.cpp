class Solution {
  public:
     void dfs(int node, vector<vector<int>>& adj, vector<int>& vis)
    {
        vis[node] = 1;
        
        for(int neighbor : adj[node])
        {
            if(!vis[neighbor])
            {
                dfs(neighbor, adj, vis);
            }
        }
    }
    int findNumberOfComponent(int V, vector<vector<int>> &edges) {

         vector<vector<int>> adj(V);
        
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V, 0);
        
        int components = 0;
        
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                components++;
                dfs(i, adj, vis);
            }
        }
        
        return components;
    }
};