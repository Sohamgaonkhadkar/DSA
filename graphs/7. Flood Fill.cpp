class Solution {
public:

    void dfs(int r, int c,
             vector<vector<int>>& image,
             int oldColor,
             int newColor)
    {
        int m = image.size();
        int n = image[0].size();

        image[r][c] = newColor;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
 
        for(int k = 0; k < 4; k++)
        {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nr < m &&
               nc >= 0 && nc < n &&
               image[nr][nc] == oldColor)
            {
                dfs(nr, nc, image, oldColor, newColor);
            }
        }
    }

    vector<vector<int>> floodFill(
        vector<vector<int>>& image,
        int sr,
        int sc,
        int color)
    {
        int oldColor = image[sr][sc];

        if(oldColor == color)
            return image;

        dfs(sr, sc, image, oldColor, color);

        return image;
    }
};
//-bfs
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int oldColor = image[sr][sc];

        if(oldColor == color)
            return image;

        int m = image.size();
        int n = image[0].size();

        queue<pair<int,int>> q;

        q.push({sr, sc});
        image[sr][sc] = color;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++)
            {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nr < m &&
                   nc >= 0 && nc < n &&
                   image[nr][nc] == oldColor)
                {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }

        return image;
    }
};