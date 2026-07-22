class Solution {
public:
    vector<string> ans;
    unordered_map<char, string> mpp;
    vector<string> letterCombinations(string digits) {
        
        ans={};
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        dfs(0,digits);
        return ans;
        
    }
    void dfs(int i,string digits){
        if(i==digits.size()){
            return;
        }
        if(i==0){
            for(char c:mpp[digits[i]]){
                ans.push_back(string(1,c));
            }
            dfs(i+1,digits);
        }else{
        vector<string> temp=ans;
        ans.clear();
        for(string s:temp){
            for(char c:mpp[digits[i]]){
                ans.push_back(s+c);
            }
        }
        dfs(i+1,digits);
        }
    }
};