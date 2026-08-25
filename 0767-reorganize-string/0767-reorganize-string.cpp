class Solution {
public:
    string reorganizeString(string s) {
         unordered_map<char,int> f;
         for(int i=0; i<s.size(); i++)
          f[s[i]]++;
        int seat = 0;
        string res = "";
        priority_queue<pair<int,char>> pq;
        for(auto i : f){
            char letter = i.first;
            int freq = i.second;
            pair<int,char> curr = {freq,letter};
            pq.push(curr);
        }
        while(!pq.empty()){
            pair<int,char> p = pq.top();
            pq.pop();
            if(seat == 0 || res[seat-1] != p.second){
                res.push_back(p.second);
                seat++;
                p.first--;
                if(p.first > 0)
                 pq.push(p);
            }
            else{
                if(pq.empty())
                 return "";
                pair<int,char> p1 = pq.top();
                pq.pop();
                res.push_back(p1.second);
                seat++;
                p1.first--;
                if(p1.first > 0)
                 pq.push(p1);
                pq.push(p);
            }
        }
        return res;
    }
};