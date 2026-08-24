class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            pair<int,int> p = {dist,i};
        if(pq.size() < k){
            pq.push(p);
            continue;
        }
        if(p.first < pq.top().first){
            pq.pop();
            pq.push(p);
        }
    }
        vector<vector<int>> ans;
        while(!pq.empty()){
            int index = pq.top().second;
            ans.push_back(points[index]);
            pq.pop();
        }
        return ans;
    }
};