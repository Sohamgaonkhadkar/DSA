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
               board[nr][nc]=='O')
            {
                dfs(nr,nc,board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        // First and last column
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
                dfs(i,0,board);

            if(board[i][n-1]=='O')
                dfs(i,n-1,board);
        }

        // First and last row
        for(int j=0;j<n;j++)
        {
            if(board[0][j]=='O')
                dfs(0,j,board);

            if(board[m-1][j]=='O')
                dfs(m-1,j,board);
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';

                else if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
};

//-bfs
class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>> q;

        // First & Last Column
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O')
            {
                board[i][0]='#';
                q.push({i,0});
            }

            if(board[i][n-1]=='O')
            {
                board[i][n-1]='#';
                q.push({i,n-1});
            }
        }

        // First & Last Row
        for(int j=0;j<n;j++)
        {
            if(board[0][j]=='O')
            {
                board[0][j]='#';
                q.push({0,j});
            }

            if(board[m-1][j]=='O')
            {
                board[m-1][j]='#';
                q.push({m-1,j});
            }
        }

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();

            for(int k=0;k<4;k++)
            {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 && nr<m &&
                   nc>=0 && nc<n &&
                   board[nr][nc]=='O')
                {
                    board[nr][nc]='#';
                    q.push({nr,nc});
                }
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';

                else if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
};