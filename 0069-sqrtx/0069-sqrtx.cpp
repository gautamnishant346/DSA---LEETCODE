class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        long long res = -1;
        while(low <= high){
        long long mid = (low + high) / 2;
        if(mid * mid == x)
         return mid;
        else if(mid * mid < x){
         res = mid;
         low = mid + 1;
        }
        else
         high = mid - 1;
        }
        return res;
    }
};