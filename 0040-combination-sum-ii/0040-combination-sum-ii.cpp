class Solution {
public:
void fun(vector<int> arr,int n,int i,int sum,vector<int> dairy,vector<vector<int>>& res,int tar)
{
    if(i == n){
        if(sum == tar)
         res.push_back(dairy);
        return;
    }
    // Dont Take
    int j = i;
    while(j+1 < n && arr[j] == arr[j+1]){
       j++;
    }
    fun(arr,n,j+1,sum,dairy,res,tar);
    // Take
    if(arr[i] + sum <= tar){
     dairy.push_back(arr[i]);
     sum += arr[i];
     fun(arr,n,i+1,sum,dairy,res,tar);
     dairy.pop_back();
     sum -= arr[i];
    }

    return;
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        int sum = 0;
        vector<int> dairy;
        vector<vector<int>> res;

        fun(candidates,n,0,sum,dairy,res,target);

        return res;
    }
};