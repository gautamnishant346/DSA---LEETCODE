class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int> f;
        int n = nums.size();
        for(int i=0; i<n; i++){
           f[nums[i]]++;
        }
        int middle = n / 2;
        for(auto it : f){
            if(it.first == nums[middle]){
                return it.second == 1;
            }
        }
        return false;
    }
};