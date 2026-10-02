class Solution {
public:

    void topo(int node,
              vector<pair<int,int>> adj[],
              vector<int>& vis,
              stack<int>& st){

        vis[node] = 1;

        for(auto it : adj[node]){
            int v = it.first;

            if(!vis[v]){
                topo(v, adj, vis, st);
            }
        }

        st.push(node);
    }

    vector<int> shortestPath(int N,
                             int M,
                             vector<vector<int>>& edges) {

        vector<pair<int,int>> adj[N];

        for(auto &it : edges){

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        vector<int> vis(N, 0);
        stack<int> st;

        for(int i=0;i<N;i++){
            if(!vis[i]){
                topo(i, adj, vis, st);
            }
        }

        vector<int> dist(N, 1e9);
        dist[0] = 0;

        while(!st.empty()){

            int node = st.top();
            st.pop();

            if(dist[node] != 1e9){

                for(auto it : adj[node]){

                    int v = it.first;
                    int wt = it.second;

                    if(dist[node] + wt < dist[v]){
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        for(int i=0;i<N;i++){
            if(dist[i] == 1e9)
                dist[i] = -1;
        }

        return dist;
    }
};