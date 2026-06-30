class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())   // Agar lengths same nhi ha to Anagram kbhi nhi ho skta
         return false;
        unordered_map<char,int> mp;
        // s.size() == t.size() ya fir n = s.size();
        for(int i=0; i<s.size(); i++){   // loop s ka liye nhi index k liye lga hai
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto it : mp)
        if(it.second != 0)
         return false;
        return true;
    }
};