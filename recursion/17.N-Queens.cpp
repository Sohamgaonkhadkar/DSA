class Solution {
public:

    void solve(int row,
               int n,
               vector<string>& board,
               vector<vector<string>>& ans,
               vector<int>& leftRow,
               vector<int>& upperDiag,
               vector<int>& lowerDiag) {

        // Base case
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {

            // Check safe
            if (leftRow[col] == 0 &&
                lowerDiag[row + col] == 0 &&
                upperDiag[n - 1 + col - row] == 0) {

                // Place queen
                board[row][col] = 'Q';

                leftRow[col] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[n - 1 + col - row] = 1;

                // Move next row
                solve(row + 1,
                      n,
                      board,
                      ans,
                      leftRow,
                      upperDiag,
                      lowerDiag);

                // Backtrack
                board[row][col] = '.';

                leftRow[col] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n);

        string s(n, '.');

        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        vector<int> leftRow(n, 0);
        vector<int> upperDiag(2*n - 1, 0);
        vector<int> lowerDiag(2*n - 1, 0);

        solve(0,
              n,
              board,
              ans,
              leftRow,
              upperDiag,
              lowerDiag);

        return ans;
    }
};