class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        dist[0][0] = grid[0][0];

        pq.push({grid[0][0], {0,0}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if(row == n-1 && col == n-1)
                return time;

            for(int k = 0; k < 4; k++) {

                int nr = row + dr[k];
                int nc = col + dc[k];

                if(nr >= 0 && nc >= 0 &&
                   nr < n && nc < n) {

                    int newTime =
                        max(time, grid[nr][nc]);

                    if(newTime < dist[nr][nc]) {

                        dist[nr][nc] = newTime;

                        pq.push({
                            newTime,
                            {nr, nc}
                        });
                    }
                }
            }
        }

        return -1;
    }
};
//-2
class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        DisjointSet ds(n * n);

        // pos[value] = {row,col}
        vector<pair<int,int>> pos(n * n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }

        vector<vector<int>> active(n, vector<int>(n, 0));

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for(int t = 0; t < n * n; t++) {

            auto [row, col] = pos[t];

            active[row][col] = 1;

            int node = row * n + col;

            // connect with already active neighbours
            for(int k = 0; k < 4; k++) {

                int nr = row + dr[k];
                int nc = col + dc[k];

                if(nr >= 0 && nc >= 0 &&
                   nr < n && nc < n &&
                   active[nr][nc]) {

                    int adjNode = nr * n + nc;

                    ds.unionBySize(node, adjNode);
                }
            }

            // start = 0
            // end = n*n - 1
            if(ds.findUPar(0) ==
               ds.findUPar(n * n - 1)) {

                return t;
            }
        }

        return -1;
    }
};