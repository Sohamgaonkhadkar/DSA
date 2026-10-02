class Solution {
public:
    int n;

    int dfs(int r, int c, int id, vector<vector<int>>& grid) {
        if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != 1)
            return 0;

        grid[r][c] = id;

        return 1 +
               dfs(r + 1, c, id, grid) +
               dfs(r - 1, c, id, grid) +
               dfs(r, c + 1, id, grid) +
               dfs(r, c - 1, id, grid);
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();

        unordered_map<int, int> size;
        int id = 2;

        // Step 1: Label islands and store their sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    size[id] = dfs(i, j, id, grid);
                    id++;
                }
            }
        }

        int ans = 0;

        // Case: grid already full of 1s
        for (auto &it : size) {
            ans = max(ans, it.second);
        }

        vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        // Step 2: Try every 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) {

                    unordered_set<int> islands;

                    for (auto &[dr, dc] : dir) {
                        int nr = i + dr;
                        int nc = j + dc;

                        if (nr >= 0 && nc >= 0 &&
                            nr < n && nc < n &&
                            grid[nr][nc] > 1) {

                            islands.insert(grid[nr][nc]);
                        }
                    }

                    int currSize = 1; // flipped cell

                    for (int islandId : islands) {
                        currSize += size[islandId];
                    }

                    ans = max(ans, currSize);
                }
            }
        }

        return ans;
    }
};
//-2
class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
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
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        DisjointSet ds(n * n);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Step 1: connect all 1's
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 0)
                    continue;

                for (int k = 0; k < 4; k++) {

                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (nr >= 0 && nc >= 0 &&
                        nr < n && nc < n &&
                        grid[nr][nc] == 1) {

                        int node = row * n + col;
                        int adjNode = nr * n + nc;

                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        int ans = 0;

        // Step 2: try converting each 0
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {

                if (grid[row][col] == 1)
                    continue;

                unordered_set<int> components;

                for (int k = 0; k < 4; k++) {

                    int nr = row + dr[k];
                    int nc = col + dc[k];

                    if (nr >= 0 && nc >= 0 &&
                        nr < n && nc < n &&
                        grid[nr][nc] == 1) {

                        int adjNode = nr * n + nc;

                        components.insert(
                            ds.findUPar(adjNode)
                        );
                    }
                }

                int totalSize = 1;

                for (auto parent : components) {
                    totalSize += ds.size[parent];
                }

                ans = max(ans, totalSize);
            }
        }

        // Step 3: handle all-1 grid
        for (int i = 0; i < n * n; i++) {
            ans = max(ans,
                      ds.size[ds.findUPar(i)]);
        }

        return ans;
    }
};