class Solution {
public:

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {

            for(int j = 0; j < 9; j++) {

                // Empty cell found
                if(board[i][j] == '.') {

                    // Try digits 1 to 9
                    for(char c = '1'; c <= '9'; c++) {

                        if(isValid(board, i, j, c)) {

                            board[i][j] = c;

                            // Recursive call
                            if(solve(board) == true)
                                return true;

                            // Backtrack
                            else
                                board[i][j] = '.';
                        }
                    }

                    // No number worked
                    return false;
                }
            }
        }

        // Sudoku solved
        return true;
    }

    bool isValid(vector<vector<char>>& board,
                 int row,
                 int col,
                 char c) {

        for(int i = 0; i < 9; i++) {

            // Row check
            if(board[row][i] == c)
                return false;

            // Column check
            if(board[i][col] == c)
                return false;

            // 3x3 box check
            if(board[(row/3)*3 + i/3]
                    [(col/3)*3 + i%3] == c)
                return false;
        }

        return true;
    }
};