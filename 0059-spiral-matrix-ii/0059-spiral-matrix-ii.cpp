class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int sRow = 0, sCol = 0;
        int eRow = n-1, eCol = n-1;
        int num = 1;
        while(sRow <= eRow && sCol <= eCol){
            // Top
            for(int j=sCol; j<=eCol; j++)
             matrix[sRow][j] = num++;
            
            // Right
            for(int i=sRow+1; i<=eRow; i++)
             matrix[i][eCol] = num++;
            
            // Bottom
            for(int j=eCol-1; j>=sCol; j--)
             matrix[eCol][j] = num++;
            
            // Left
            for(int i=eRow-1; i>=sRow+1; i--)
             matrix[i][sCol] = num++;

            // Inner Boundaries
            sRow++; sCol++;
            eRow--; eCol--;
        }
        return matrix;
    }
};