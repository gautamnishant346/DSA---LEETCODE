class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size());
        res[temperatures.size()-1] = 0;
        st.push(temperatures.size()-1);
        for(int i=temperatures.size()-2; i>=0; i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){
                st.pop();
            }
            if(st.empty())
             res[i] = 0;
            else
             res[i] = st.top() - i;
            st.push(i);
        }
        return res;
    }
};