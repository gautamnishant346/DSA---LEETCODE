class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i = 0;
        int maxEnding = nums[i];
        int minEnding = nums[i];
        int ans = nums[i];
        for(i=1; i<nums.size(); i++){
            int v1 = nums[i];
            int v2 = maxEnding * nums[i];
            int v3 = minEnding * nums[i];
            maxEnding = max(v1,max(v2,v3));
            minEnding = min(v1,min(v2,v3));
            ans = max(ans,max(maxEnding,minEnding));
        }
        return ans;
    }
};