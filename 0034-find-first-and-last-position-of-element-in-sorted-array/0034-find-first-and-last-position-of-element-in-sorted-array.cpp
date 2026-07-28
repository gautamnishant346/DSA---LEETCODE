class Solution {
public:
int first(vector<int> arr, int x){
    int low = 0;
    int high = arr.size()-1;
    int res = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] < x)
         low = mid + 1;
        else if(arr[mid] > x)
         high = mid - 1;
        else{
            res = mid;      // yaad rkhege
            high = mid - 1;
        }
    }
    return res;
}
int last(vector<int> arr, int x){
    int low = 0;
    int high = arr.size()-1;
    int res = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] < x)
         low = mid + 1;
        else if(arr[mid] > x)
         high = mid - 1;
        else{
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}
    vector<int> searchRange(vector<int>& nums, int target) {
       int f =  first(nums,target);
       int l =  last(nums,target);
       return {f,l};
    }
};