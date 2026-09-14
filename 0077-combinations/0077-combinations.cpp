class Solution {
public:
void fun(int n,int k,int start,vector<int> tmp,vector<vector<int>>& ans){
   // k elements choose krne ha
   if(tmp.size() == k){
    ans.push_back(tmp);
    return;
   }
   // next element choose krne
   for(int j=start; j<=n; j++){
    tmp.push_back(j);
    fun(n,k,j+1,tmp,ans);
    tmp.pop_back();
   }
}
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        vector<vector<int>> ans;
        fun(n,k,1,tmp,ans);

        return ans;
    }
};