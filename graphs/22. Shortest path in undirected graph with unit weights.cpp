class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n, int m) {

      vector<int> adj[n];

      for(auto &it : edges){
          int u = it[0];
          int v = it[1];

          adj[u].push_back(v);
          adj[v].push_back(u);
      }

      vector<int> dist(n, 1e9);

      queue<int> q;

      dist[0] = 0;
      q.push(0);

      while(!q.empty()){

          int node = q.front();
          q.pop();

          for(auto nbr : adj[node]){

              if(dist[node] + 1 < dist[nbr]){
                  dist[nbr] = dist[node] + 1;
                  q.push(nbr);
              }
          }
      }

      for(int i=0;i<n;i++){
          if(dist[i] == 1e9)
              dist[i] = -1;
      }

      return dist;
  }
};
