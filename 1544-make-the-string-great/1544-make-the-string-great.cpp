class Solution {
public:
    string makeGood(string s) {
        string res;
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(st.empty()){
             st.push(s[i]);
             continue;
            }
            if(abs(st.top() - s[i]) == 32){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};