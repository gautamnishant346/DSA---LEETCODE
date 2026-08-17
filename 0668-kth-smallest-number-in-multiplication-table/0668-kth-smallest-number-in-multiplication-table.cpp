class Solution {
public:
int fun(int m,int n,int guess){
    int row = n-1;
    int col = 0;
    int count = 0;
    while(row >= 0 && col < m){
        if((row + 1) * (col + 1) <= guess){
            count += row + 1;
            col++;
        }
        else
         row--;
    }
    return count;
}
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m * n;
        int res = -1;
        while(low <= high){
            int guess = (low + high) / 2;
            int ans = fun(n,m,guess);
            if(ans < k)
             low = guess + 1;
            else{    // ans >= k
               res = guess;
               high = guess - 1;
            }
        }
        return res;
    }
};