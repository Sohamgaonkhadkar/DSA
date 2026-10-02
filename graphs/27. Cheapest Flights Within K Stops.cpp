class Solution {
public:
    int findCheapestPrice(int n,
                          vector<vector<int>>& flights,
                          int src,
                          int dst,
                          int k) {

        vector<pair<int,int>> adj[n];

        for(auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        // {cost, node, edges_used}
        pq.push({0, src, 0});
        dist[src][0] = 0;

        while(!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int cost  = cur[0];
            int node  = cur[1];
            int edges = cur[2];

            if(node == dst)
                return cost;

            if(edges == k + 1)
                continue;

            for(auto &[adjNode, wt] : adj[node]) {

                int newCost = cost + wt;

                if(newCost < dist[adjNode][edges + 1]) {

                    dist[adjNode][edges + 1] = newCost;

                    pq.push({
                        newCost,
                        adjNode,
                        edges + 1
                    });
                }
            }
        }

        return -1;
    }
};
//-2
class Solution {
public:
    int findCheapestPrice(int n,
                          vector<vector<int>>& flights,
                          int src,
                          int dst,
                          int k) {

        vector<pair<int,int>> adj[n];

        for(auto &it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, INT_MAX);

        queue<pair<int,pair<int,int>>> q;
        q.push({0, {src, 0}}); // stops, {node, cost}

        dist[src] = 0;

        while(!q.empty()){

            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node  = it.second.first;
            int cost  = it.second.second;

            if(stops > k)
                continue;

            for(auto nbr : adj[node]){

                int adjNode = nbr.first;
                int wt      = nbr.second;

                if(cost + wt < dist[adjNode]){

                    dist[adjNode] = cost + wt;

                    q.push({
                        stops + 1,
                        {adjNode, cost + wt}
                    });
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};