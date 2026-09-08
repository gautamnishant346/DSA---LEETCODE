class Solution {
public:
void fun(vector<int>& nums,int i,vector<int>& temp,vector<vector<int>>& ans){
    if(i == nums.size()){
        ans.push_back(temp);
        return;
    }
    // Include
    temp.push_back(nums[i]);
    fun(nums,i+1,temp,ans);
    temp.pop_back();

    // Exclude
    while(i+1 < nums.size() && nums[i] == nums[i+1]){
        i++;
    }

    fun(nums,i+1,temp,ans);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        fun(nums,0,temp,ans);
        return ans;
    }
};