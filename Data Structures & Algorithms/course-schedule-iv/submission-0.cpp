class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        adj.resize(n);
        for(auto&q:prerequisites){
            adj[q[0]].push_back(q[1]);
        }
        vector<bool> ans;
        for(auto&r:queries){
            ans.push_back(bfs(r[0],r[1],n));
        }
        return ans;
    }
    bool bfs(int a,int b,int n){
        vector<bool> vis(n);
        queue<int> q;
        q.push(a);
        vis[a]=1;
        while(!q.empty()){
            int t=q.front();
            q.pop();
            for(int s:adj[t]){
                if(s==b)return true;
                if(!vis[s]){
                    q.push(s);
                    vis[s]=1;
                }
            }
        }
    return false;
    }

};