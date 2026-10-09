class Solution {
public:
void spiral(vector<vector<int>> &mat,int m,int n,vector<int> &res)
{
  int sRow = 0, sCol = 0;
  int eRow = m-1, eCol = n-1;
    while(sRow <= eRow && sCol <= eCol)
    {
       // Top
       for(int j=sCol; j<=eCol; j++){
         res.push_back(mat[sRow][j]);
       }
       // Right
       for(int i=sRow+1; i<=eRow; i++){
         res.push_back(mat[i][eCol]);
       }
       // Bottom
       for(int j=eCol-1; j>=sCol; j--){
         if(sRow == eRow)   // middle
          break;
         res.push_back(mat[eRow][j]);
       }
       // Left
       for(int i=eRow-1; i>=sRow+1; i--){
         if(sCol == eCol)  // middle
           break;
         res.push_back(mat[i][sCol]);
       }
       sRow++; sCol++;
       eRow--; eCol--;
    }
}
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        spiral(matrix,m,n,res);

        return res;
    }
};