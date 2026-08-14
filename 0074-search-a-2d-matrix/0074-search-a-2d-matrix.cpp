class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if(matrix.empty() || matrix[0].empty())
         return false;
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 0;
        int high = rows * cols - 1;
        while(low <= high){
            int guess = (low + high) / 2;
            int r = guess / cols;
            int c = guess % cols;
            if(matrix[r][c] == target)
             return true;
            if(matrix[r][c] < target)
             low = guess + 1;
            else
             high = guess - 1;
        }
         return false;
    }
};