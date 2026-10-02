class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1|| grid[grid.size()-1][grid[0].size()-1] == 1)
            return -1;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int,int>> q;
        visited[0][0] = true;
        q.push({0, 0});
        int dr[] = {-1,-1,-1, 0,0, 1,1,1};
        int dc[] = {-1, 0, 1,-1,1,-1,0,1};
        int count = 0;
        int n = grid.size();

        while(!q.empty())
        {
            int size = q.size();
            count++;
            for(int i=0; i<size; i++)
                {
                    auto it = q.front();
                    q.pop();

                    int row = it.first;
                    int col = it.second;

                    if(row == grid.size()-1 && col == grid[0].size()-1)
                        return count;
                    for(int k=0; k<8; k++)
                        {
                            int nr = row + dr[k];
                            int nc = col + dc[k];

                            if(nr>=0 && nr<n && nc>=0 && nc<n)
                            {
                                if(grid[nr][nc] == 0 && !visited[nr][nc])
                                {
                                    visited[nr][nc] = true;
                                    q.push({nr, nc});
                                }
                            }
                        }
                }
        }

        return -1;
    }
};