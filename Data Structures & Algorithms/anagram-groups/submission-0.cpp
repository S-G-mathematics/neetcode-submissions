class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        unordered_set<string> lo;
        for(string s:strs){
            string q=s;
            sort(q.begin(),q.end());
            mp[q].push_back(s);
            lo.insert(q);
        }
        vector<vector<string>> ans;
        for (string lk:lo){
            ans.push_back(mp[lk]);
        }
        return ans;
    }
};
