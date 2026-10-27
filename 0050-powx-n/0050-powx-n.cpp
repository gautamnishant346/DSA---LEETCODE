class Solution {
public:
    double myPow(double x, int n) {
        //if(n == 0) return 1.0;
        //if(x == 0) return 0.0;
        //if(x == 1) return 1.0;
        //if(x == -1 && n % 2 == 0) return 1.0;
        //if(x == -1 && n % 2 != 0) return -1.0;
        
        double ans = 1.0;
        long long binForm = n;
        bool neg = false;
        if(binForm < 0){
            neg = true;
            binForm = -binForm;
        }
        while(binForm > 0){
            if(binForm % 2 == 1){
               ans *= x;
            }
            x *= x;
            binForm /= 2;
        }
        if(neg){
           return 1.0 / ans;
        }
        return ans;
    }
};