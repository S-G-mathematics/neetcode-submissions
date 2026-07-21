class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> hh;
        for(int i=1;i<=n;i++){
            hh.push_back(i);
        }
        vector<int> curr={};
        int cnt=0;
        dfs(hh,n,k,0,curr,cnt);
        return ans;

    }
    void dfs(vector<int> &hh,int n,int k, int idx,vector<int> &curr,int &cnt){
        if(cnt==k){
            ans.push_back(curr);
            return;
        }
        if(idx==n){
            return;
        }
        for(int i=idx;i<n;i++){
            curr.push_back(hh[i]);
            cnt++;
            idx++;
            dfs(hh,n,k,idx,curr,cnt);
            curr.pop_back();
            cnt--;
        }
    }
};