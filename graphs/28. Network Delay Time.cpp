class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> adj[n + 1];

        for(auto &it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        vector<int> dist(n + 1, INT_MAX);
        
        priority_queue<
            pair<int,int>,
            vector<pair<int,in
            t>>,
            greater<pair<int,int>>
        > pq;

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){

            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto [adjNode, wt] : adj[node]){

                if(dist[node] + wt < dist[adjNode]){

                    dist[adjNode] = dist[node] + wt;

                    pq.push({
                        dist[adjNode],
                        adjNode
                    });
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++){

            if(dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};