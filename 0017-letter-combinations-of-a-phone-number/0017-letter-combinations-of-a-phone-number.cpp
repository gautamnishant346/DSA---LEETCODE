class Solution {
public:
void fun(string &s,int n,int i,string diary,vector<string>& ans){
    unordered_map<char,string> f;
    f['2'] = "abc";
    f['3'] = "def";
    f['4'] = "ghi";
    f['5'] = "jkl";
    f['6'] = "mno";
    f['7'] = "pqrs";
    f['8'] = "tuv";
    f['9'] = "wxyz";

    if(i == n){
        ans.push_back(diary);
        return;
    }
    string choice = f[s[i]];
    for(int j=0; j<choice.size(); j++){
        diary.push_back(choice[j]);
        fun(s,n,i+1,diary,ans);
        diary.pop_back();
    }
    return;
}
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        string diary = "";
        vector<string> ans;
        fun(digits,n,0,diary,ans);
        return ans;
    }
};