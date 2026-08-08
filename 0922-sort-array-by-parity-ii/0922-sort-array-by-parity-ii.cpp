class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int j = 0;
        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 0){
                ans[j] = nums[i];
                j += 2;
            }
        }
        j = 1;
        for(int i=0; i<n; i++){
            if(nums[i] % 2 == 1){
                ans[j] = nums[i];
                j += 2;
            }
        }
        return ans;
    }
};