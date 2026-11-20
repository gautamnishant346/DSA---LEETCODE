class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> f;
        for(int i=0; i<nums.size(); i++){
            f[nums[i]]++;
        }
        int sum = 0;
        for(auto it : f){
            if(it.second == 1){
                sum += it.first;
            }
        }
        return sum;
    }
};