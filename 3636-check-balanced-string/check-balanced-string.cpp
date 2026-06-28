class Solution {
public:
    bool isBalanced(string num) {
        int EvenSum = 0;
        int OddSum = 0;
        for(int i = 0; i<num.size(); i++){
            if(i%2 == 0)
             EvenSum+= num[i] - '0';   // num[i] character hai digit nhi (ASCII value add ho rhi hai)
            else
             OddSum+= num[i] - '0';   // 0 subtract krna se character digit integer bn jati hai
        }
        if(EvenSum == OddSum)
            return true;
        return false;
    }
};