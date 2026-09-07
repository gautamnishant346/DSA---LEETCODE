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

    // Exclude
    //Wapas aakar hatao
    temp.pop_back();
    // mat lo
    fun(nums,i+1,temp,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        fun(nums,0,temp,ans);
        return ans;
    }
};