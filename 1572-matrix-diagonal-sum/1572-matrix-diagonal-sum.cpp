class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size();
        for(int i=0; i<n; i++){
            sum += mat[i][i];  // Pd
            if(i != n-i-1){     // Jb i ki value j ki value ka equal nhi ha
                sum += mat[i][n-i-1];   //Sd
            }
        }
        return sum;
    }
};