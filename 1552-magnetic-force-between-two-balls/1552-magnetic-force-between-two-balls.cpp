class Solution {
public:
bool fun(vector<int> &position,int n,int m,int guess){
    int cows = 1;
    int prevcows = position[0];
    for(int i = 1; i<n; i++){
        int dist = position[i] - prevcows;
        if(dist < guess)
         continue;
        cows++;
        prevcows = position[i];
    }
    if(cows >= m)
     return true;
    else
     return false;
}
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int low = 1;
        int high = position[n-1] - position[0];
        int res = -1;
        while(low <= high){
            int guess = (low + high) / 2;
            if(fun(position,n,m,guess)){
                res = guess;
                low = guess + 1;
            }
            else
             high = guess - 1;
        }
        return res;
    }
};