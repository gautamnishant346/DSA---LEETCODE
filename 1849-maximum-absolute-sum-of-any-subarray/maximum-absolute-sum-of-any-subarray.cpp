class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int bestEnding = nums[0];
        int res = nums[0];
        for(int i=1; i<nums.size(); i++){
            int v1 = bestEnding + nums[i];
            int v2 = nums[i];
            bestEnding = max(v1,v2);
            res = max(bestEnding,res);
        }
        bestEnding = nums[0];
        int minRes = nums[0];
        for(int i=1; i<nums.size(); i++){
            int u1 = bestEnding + nums[i];
            int u2 = nums[i];
            bestEnding = min(u1,u2);
            minRes = min(minRes,bestEnding);
        }
        return max(res,abs(minRes));
    }
};