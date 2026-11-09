class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        vector<int> arr;
        for(int i=0; i<nums.size(); i++){
            if(i % 10 == nums[i]){
               arr.push_back(i);
            }
        }
        if(arr.size() >= 1){
            return arr[0];
        }
        return -1;
    }
};