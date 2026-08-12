class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n =nums.size();
        int xorSum = 0;
        for(int i=1; i<=n; i++){
          xorSum ^= i;
        }
        for(int i=0; i<n; i++){
            xorSum ^= nums[i];
        }
        return xorSum;
    }
};