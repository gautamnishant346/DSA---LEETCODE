class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int bestmax = nums[0];
        int bestmin = nums[0];
        int res = nums[0];
        int minRes = nums[0];
        int cp = 0;
        for(int i=0; i<nums.size(); i++)
         cp += nums[i];
        int total = cp;
        for(int i=1; i<nums.size(); i++){
            bestmax = max(bestmax+nums[i],nums[i]);
            bestmin = min(bestmin+nums[i],nums[i]);
            res = max(res,bestmax);
            minRes = min(minRes,bestmin);
        }
        cp -= minRes;
        if(minRes == total)
         return res;
        return max(res,cp);
    }
};