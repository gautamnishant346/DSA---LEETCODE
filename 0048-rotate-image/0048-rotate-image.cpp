class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Step 1 : Transpose of matrix
        for(int i=0; i<matrix.size(); i++){
            for(int j=i+1; j<matrix.size(); j++){
                // swap matrix[i][j],matrix[j][i]
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        // Reverse all rows of matrix
        // Har row pr jayge aur reverse kr dege
        for(int row=0; row<matrix.size(); row++){
            int startCol = 0;
            int endCol = matrix.size()-1;
            while(startCol <= endCol){
                // swap matrix[row][startCol],matrix[row][endCol]
                int temp = matrix[row][startCol];
                matrix[row][startCol] = matrix[row][endCol];
                matrix[row][endCol] = temp;
                startCol++;
                endCol--;
            }
        }
    }
};