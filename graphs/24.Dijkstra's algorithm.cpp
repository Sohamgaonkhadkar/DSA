class Solution {
public:
    vector<int> dijkstra(int V,
                         vector<vector<int>> &edges,
                         int S) {

        vector<pair<int,int>> adj[V];

        for(auto &it : edges){

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<int> dist(V, 1e9);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[S] = 0;

        pq.push({0,S});

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int dis = it.first;
            int node = it.second;

            for(auto nbr : adj[node]){

                int adjNode = nbr.first;
                int wt = nbr.second;

                if(dis + wt < dist[adjNode]){

                    dist[adjNode] = dis + wt;

                    pq.push({
                        dist[adjNode],
                        adjNode
                    });
                }
            }
        }

        return dist;
    }
};