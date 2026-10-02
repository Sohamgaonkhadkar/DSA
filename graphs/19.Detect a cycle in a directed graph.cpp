class Solution {
public:

    bool isCyclic(int V, vector<vector<int>>& adj)
    {
        vector<int> indegree(V, 0);

        for(int i = 0; i < V; i++)
        {
            for(int neigh : adj[i])
            {
                indegree[neigh]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < V; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            count++;

            for(int neigh : adj[node])
            {
                indegree[neigh]--;

                if(indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        return count != V;
    }
};