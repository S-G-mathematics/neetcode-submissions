class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string s="";
        dfs(n,0,0,s);
        return ans;
    }
    void dfs(int n,int a,int b,string cr){
        if(a<b || a>n) return;
        if(cr.size()==2*n && a==b){
            ans.push_back(cr);
            return;
        }
        cr=cr+'(';
        a++;
        dfs(n,a,b,cr);
        cr.pop_back();
        a--;
        cr=cr+')';
        b++;
        dfs(n,a,b,cr);
        cr.pop_back();
        b--;
    }
};
