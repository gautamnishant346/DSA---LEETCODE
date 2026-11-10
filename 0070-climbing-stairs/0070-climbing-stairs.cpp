class Solution {
public:

    int solve(int n, vector<int>& dp) {

        // Base case
        if(n == 1) return 1;
        if(n == 2) return 2;

        // Agar answer pehle calculate ho chuka hai
        if(dp[n] != -1) {
            return dp[n];
        }

        // Answer calculate karke store karenge
        dp[n] = solve(n-1, dp) + solve(n-2, dp);

        return dp[n];
    }

    int climbStairs(int n) {

        vector<int> dp(n+1, -1);

        return solve(n, dp);
    }
};