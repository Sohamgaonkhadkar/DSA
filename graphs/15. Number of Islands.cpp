class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board)
    {
        int m = board.size();
        int n = board[0].size();

        board[r][c] = '#';

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int k=0;k<4;k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr>=0 && nr<m &&
               nc>=0 && nc<n &&
               board[nr][nc]=='1')
            {
                dfs(nr,nc,board);
            }
        }
    }

    int numIslands(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int islands = 0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='1')
                {
                    dfs(i,j,board);
                    islands++;
                }
            }
        }
        return islands;
    }
};