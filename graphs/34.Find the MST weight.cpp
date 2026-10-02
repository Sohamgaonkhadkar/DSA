class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> vis(V, 0);

        pq.push({0, 0}); // {weight, node}

        int sum = 0;

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second;

            if(vis[node]) continue;

            vis[node] = 1;
            sum += wt;

            for(auto &nbr : adj[node]) {

                int adjNode = nbr[0];
                int edgeWt = nbr[1];

                if(!vis[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }

        return sum;
    }
};