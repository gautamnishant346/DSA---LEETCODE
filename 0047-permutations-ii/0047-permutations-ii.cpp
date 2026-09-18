class Solution {
public:
void getPermute(vector<int>& nums,int idx,vector<vector<int>>& ans)
{
    if(idx == nums.size()){
        ans.push_back(nums);
        return;
    }
     set<int> used;   // Current level ke duplicates trck krega
     
    for(int i=idx; i<nums.size(); i++){
        // Agar iss level pe ye already use ho chuki ha
        if(used.count(nums[i])){
            continue;
        }
        used.insert(nums[i]);
        swap(nums[idx],nums[i]);
        getPermute(nums,idx+1,ans);
        swap(nums[idx],nums[i]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        getPermute(nums,0,ans);

        return ans;
    }
};