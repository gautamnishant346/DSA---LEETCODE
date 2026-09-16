class Solution {
public:
void fun(int n,int k,int i,vector<int> tmp,vector<vector<int>>& res,int sum)
{
    if(tmp.size() == k){
        if(sum == n)
         res.push_back(tmp);
        return;
    }
    for(int j=i+1; j<10; j++){
        tmp.push_back(j);
        fun(n,k,j,tmp,res,sum+j);
        tmp.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        int sum = 0;
        fun(n,k,0,tmp,res,sum);

        return res;
    }
};