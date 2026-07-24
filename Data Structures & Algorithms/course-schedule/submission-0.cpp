class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto&q:prerequisites){
            adj[q[1]].push_back(q[0]);
        }
        vector<int> color(n,0);
        for(int i=0;i<n;i++){
            if(color[i]==0 && !dfs(i,adj,color)) return false;
        }
        return true;
    }
    bool dfs(int t,vector<vector<int>>&adj,vector<int>&color){
        color[t]=1;
        for(int q:adj[t]){
            if(color[q]==1){
                return false;
            }
            if(color[q]==0){
                if(!dfs(q,adj,color))return false;
            }
        }
        color[t]=2;
        return true;
    }
};
