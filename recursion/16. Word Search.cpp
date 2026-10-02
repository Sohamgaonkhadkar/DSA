class Solution {
public:

    bool solve(int row,
               int col,
               int idx,
               vector<vector<char>>& board,
               string& word){

        // Entire word matched
        if(idx == word.size())
            return true;

        int n = board.size();
        int m = board[0].size();

        // Invalid conditions
        if(row < 0 || col < 0 ||
           row >= n || col >= m ||
           board[row][col] != word[idx])
            return false;

        // Mark visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Explore 4 directions
        bool found =
            solve(row + 1, col, idx + 1, board, word) ||
            solve(row - 1, col, idx + 1, board, word) ||
            solve(row, col + 1, idx + 1, board, word) ||
            solve(row, col - 1, idx + 1, board, word);

        // Backtrack
        board[row][col] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board,
               string word) {

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                if(solve(i, j, 0, board, word))
                    return true;
            }
        }

        return false;
    }
};