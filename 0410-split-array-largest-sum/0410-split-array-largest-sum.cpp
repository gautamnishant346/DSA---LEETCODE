class Solution {
public:
bool fun(vector<int>nums,int n,int limit,int k){
    int m = 1;
    int page = 0;
    for(int i=0; i<n; i++){
        if(page+nums[i] <= limit)
         page = page + nums[i];
        else{
            m++;
            page = nums[i];
            if(m > k)
             return false;
        }
    }
    return true;
}
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k)
         return -1;
        int low = 0,high = 0;
        for(int i=0; i<n; i++){
            low = max(low,nums[i]);
            high += nums[i];
        }
        int res = -1;
        while(low <= high){
            int guess = (low + high) / 2;
            if(fun(nums,n,guess,k)){
                res = guess;
                high = guess - 1;
            }
            else
             low = guess + 1;
        }
        return res;
    }
};