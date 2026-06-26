class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i = 0;
        int bestEnding = nums[i];
        int ans = nums[i];
        for(i=1; i<nums.size(); i++){
            int v1 = bestEnding + nums[i];
            int v2 = nums[i];
            bestEnding = max(v1,v2);
            ans = max(ans,bestEnding);
        }
        return ans;        
    }
};