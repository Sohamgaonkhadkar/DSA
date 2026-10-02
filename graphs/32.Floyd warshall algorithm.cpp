class Solution {
public:
    void shortestDistance(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Convert -1 to INF
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == -1)
                    matrix[i][j] = 1e9;

                if(i == j)
                    matrix[i][j] = 0;
            }
        }

        // Floyd Warshall
        for(int via = 0; via < n; via++) {

            for(int i = 0; i < n; i++) {

                for(int j = 0; j < n; j++) {

                    matrix[i][j] =
                    min(matrix[i][j],
                        matrix[i][via] + matrix[via][j]);
                }
            }
        }

        // Convert INF back to -1
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == 1e9)
                    matrix[i][j] = -1;
            }
        }
    }
};