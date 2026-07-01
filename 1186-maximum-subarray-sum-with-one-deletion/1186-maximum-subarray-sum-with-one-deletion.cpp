class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDelete = arr[0];
        int oneDelete = INT_MIN;
        int res = arr[0];
        int v2;
        for(int i=1; i<arr.size(); i++){
            int prevnoDelete = noDelete;
            int prevoneDelete = oneDelete;
            noDelete = max(noDelete+arr[i],arr[i]);
            if(prevoneDelete == INT_MIN)
             v2 = arr[i];
            else
             v2 = prevoneDelete + arr[i];

            oneDelete = max(v2,prevnoDelete);
            res = max(res,max(noDelete,oneDelete));
        }
        return res;
    }
};