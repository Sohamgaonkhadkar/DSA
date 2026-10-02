//brute
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> row(rows, 0);
        vector<int> col(cols, 0);

        // PASS 1: CHECK (observe only)
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // PASS 2: EDIT rows
        for (int i = 0; i < rows; i++) {
            if (row[i] == 1) {
                for (int j = 0; j < cols; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // PASS 2: EDIT columns
        for (int j = 0; j < cols; j++) {
            if (col[j] == 1) {
                for (int i = 0; i < rows; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

//optimal
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int col0=1;


        // PASS 1: CHECK (observe only)
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if(matrix[i][j]==0){
                    matrix[i][0]=0;

                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else{
                        col0=0;
                    }
                }
            }
        }

        for (int i = 1; i < rows; i++) {
                for (int j = 1; j < cols; j++) {
                    if(matrix[i][j]!=0){
                        if(matrix[0][j]==0||matrix[i][0]==0){
                            matrix[i][j]=0;
                        }
                    }
                }
        }

        if(matrix[0][0]==0){
            for(int j=0;j<cols;j++) matrix[0][j]=0;
        }
        if(col0==0){
            for(int i=0;i<rows;i++){
                matrix[i][0]=0;
            }
        }
        
        
    }
};
