class Solution {
public:
    
    void dfs(int r, int c, vector<vector<int>>& board)
    {
        int m = board.size();
        int n = board[0].size();

        board[r][c] = 0;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int k=0;k<4;k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr>=0 && nr<m &&
               nc>=0 && nc<n &&
               board[nr][nc]==1)
            {
                dfs(nr,nc,board);
            }
        }
    }4
    int numEnclaves(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        // First and last column
        for(int i=0;i<m;i++)
        {
            if(board[i][0]==1)
                dfs(i,0,board);

            if(board[i][n-1]==1)
                dfs(i,n-1,board);
        }

        // First and last row
        for(int j=0;j<n;j++)
        {
            if(board[0][j]==1)
                dfs(0,j,board);

            if(board[m-1][j]==1)
                dfs(m-1,j,board);
        }
        int enclaves = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1)
                    enclaves++;
                    
            }
        }
        return enclaves;
    }
};