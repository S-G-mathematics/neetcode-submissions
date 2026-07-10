class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int q=strs[0].size();
        string x="";
        for(int j=0;j<q;j++){
            char v=strs[0][j];
        for(int i=0;i<n;i++){
            if(v!=strs[i][j] || j>strs[i].size()) return x;
        }
            x=x+v;
        }
        return x;
    }
};