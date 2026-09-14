class Solution {
public:
void fun(vector<int> arr,int n,int idx,vector<int> dairy,int sum,vector<vector<int>>& ans,int tar)
{
    if(idx == n){
        if(sum == tar)
         ans.push_back(dairy);
        return;
    }

    // Nahi lege
    fun(arr,n,idx+1,dairy,sum,ans,tar);

    // Choice 2 : Lege
    if(arr[idx] + sum <=tar){
        dairy.push_back(arr[idx]);
        sum += arr[idx];
        fun(arr,n,idx,dairy,sum,ans,tar);
        dairy.pop_back();
        sum -= arr[idx];
    }
    return;
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum = 0;
        int idx = 0;
        vector<int> dairy;
        vector<vector<int>> ans;

        fun(candidates,n,idx,dairy,sum,ans,target);
        return ans;
    }
};