class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, MaxCount = 0;
        
        for(int j=0; j<nums.size(); j++){
            if(nums[j] == 1){
                count++;
                MaxCount = max(MaxCount,count);
            }
            else{
              count = 0;
            }
        }
        return MaxCount;
    }
};