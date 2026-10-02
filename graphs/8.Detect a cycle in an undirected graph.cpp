class Solution {
public:

    bool dfs(int node, int parent,
             vector<vector<int>>& adj,
             vector<int>& vis)
    {
        vis[node] = 1;

        for(int neighbor : adj[node])
        {
            if(!vis[neighbor])
            {
                if(dfs(neighbor, node, adj, vis))
                    return true;
            }
            else if(neighbor != parent)
            {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V, 0);

        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, -1, adj, vis))
                    return true;
            }
        }

        return false;
    }
};