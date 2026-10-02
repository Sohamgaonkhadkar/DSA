class Solution {
public:

    bool dfs(int node,
             vector<vector<int>>& graph,
             vector<int>& state)
    {
        if(state[node] == 1)
            return false; // cycle found

        if(state[node] == 2)
            return true; // already safe

        state[node] = 1; // visiting

        for(int neigh : graph[node])
        {
            if(!dfs(neigh, graph, state))
                return false;
        }

        state[node] = 2; // safe

        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n = graph.size();

        vector<int> state(n, 0);

        vector<int> ans;

        for(int i = 0; i < n; i++)
        {
            if(dfs(i, graph, state))
                ans.push_back(i);
        }

        return ans;
    }
};
//-2
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<vector<int>> rev(n);
        vector<int> outdegree(n,0);

        for(int i=0;i<n;i++)
        {
            outdegree[i] = graph[i].size();

            for(int neigh : graph[i])
            {
                rev[neigh].push_back(i);
            }
        }

        queue<int> q;

        for(int i=0;i<n;i++)
        {
            if(outdegree[i] == 0)
                q.push(i);
        }

        vector<int> safe;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            safe.push_back(node);

            for(int parent : rev[node])
            {
                outdegree[parent]--;

                if(outdegree[parent] == 0)
                    q.push(parent);
            }
        }

        sort(safe.begin(), safe.end());

        return safe;
    }
};