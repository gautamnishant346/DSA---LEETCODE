class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size()-1;
        int row = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(matrix[mid][0] <= target){
                row = mid;
                low = mid + 1;
            }
            else
              high = mid - 1;
        }
        if(row == -1)
         return false;
        int low1 = 0;
        int high1 = matrix[row].size()-1;
        while(low1 <= high1){
            int guess = (low1 + high1) / 2;
            if(matrix [row][guess] == target)
              return true;
            if(matrix [row][guess] < target)
             low1 = guess + 1;
            else
             high1 = guess - 1;
        }
        return false;
    }
};