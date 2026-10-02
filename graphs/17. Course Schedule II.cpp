class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto &p : prerequisites)
        {
            int course = p[0];
            int prereq = p[1];

            adj[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(int neighbor : adj[node])
            {
                indegree[neighbor]--;

                if(indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        return topo.size() == numCourses ? topo : vector<int>();
    }
};