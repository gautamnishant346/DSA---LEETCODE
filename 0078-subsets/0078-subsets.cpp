class Solution {
public:
void fun(vector<int>& nums,int i,vector<int>& temp,vector<vector<int>>& ans){
    if(i == nums.size()){
        ans.push_back(temp);
        return;
    }
    // nhi lege to direct aaga jump krege
    fun(nums,i+1,temp,ans);

    // lege -> pehle temp ma add fir aaga bdege
    temp.push_back(nums[i]);
    fun(nums,i+1,temp,ans);
    // Wapas aana ka liye
    temp.pop_back();

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        fun(nums,0,temp,ans);
        return ans;
    }
};