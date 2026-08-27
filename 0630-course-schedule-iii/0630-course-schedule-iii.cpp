class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int time = 0;
        priority_queue<int> pq;
        for(int i=0; i<courses.size(); i++){
            int duration = courses[i][0];
            int deadline = courses[i][1];
            time += duration;
            pq.push(duration);
            if(time > deadline){
              time -= pq.top();
              pq.pop();
            }
        }
        return pq.size();
    }
};