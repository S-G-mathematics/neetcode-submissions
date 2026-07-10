class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string s:strs){
            string q=s;
            sort(q.begin(),q.end());
            mp[q].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto &p:mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};
