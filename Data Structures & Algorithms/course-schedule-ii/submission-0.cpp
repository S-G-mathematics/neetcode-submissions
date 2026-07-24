class Solution {
public:
    vector<vector<int>> adj;
    vector<int> color;
    vector<int> ans;
    vector<int> findOrder(int n, vector<vector<int>>& p) {
            adj.resize(n);
            color.resize(n,0);        
        for(auto&q:p){
            adj[q[1]].push_back(q[0]);
        }
        for(int i=0;i<n;i++){
            if(color[i]==0){
                if(!dfs(i))return {};
            }
        }
        if(ans.size()!=n)return {};
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
    bool dfs(int t){
        color[t]=1;
        for(int q:adj[t]){
            if(color[q]==1) return false;
            if(color[q]==0){
                if(!dfs(q))return false;
            }
        }
        color[t]=2;
        ans.push_back(t);
        return true;
    }
};
