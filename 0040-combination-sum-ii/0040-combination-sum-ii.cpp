class Solution {
public:
void fun(vector<int> arr,int n,int i,int sum,vector<int> tmp,vector<vector<int>>& res,int target)
{
    if(sum > target) return;
    if(i == n){
        if(sum == target)
         res.push_back(tmp);
        return;
    }
    // Choice 1 : Pick
    tmp.push_back(arr[i]);
    fun(arr,n,i+1,sum+arr[i],tmp,res,target);
    tmp.pop_back();

    // Choice 2 : Not Pick
    int j = i+1;
    while(j < n && arr[j] == arr[i]){
        j++;
    }
    fun(arr,n,j,sum,tmp,res,target);
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(),candidates.end());
      int n = candidates.size();
      vector<int> tmp;
      vector<vector<int>> res;
      fun(candidates,n,0,0,tmp,res,target);

      return res;
    }
};