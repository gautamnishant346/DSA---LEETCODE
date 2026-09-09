class Solution {
public:
void fun(vector<int>& nums,int i,vector<int>& tmp,vector<vector<int>>& res){
    if(i == nums.size()){
        res.push_back(tmp);
        return;
    }

    //nhi lenge
    int j=i;
    while(j+1 < nums.size() && nums[j] == nums[j+1]){
        j++;
    }
    fun(nums,j+1,tmp,res);

    // lenge
    tmp.push_back(nums[i]);
    fun(nums,i+1,tmp,res);
    tmp.pop_back();

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<int> tmp;
      vector<vector<int>> res;
      sort(nums.begin(),nums.end());
      fun(nums,0,tmp,res);

      return res;  
    }
};