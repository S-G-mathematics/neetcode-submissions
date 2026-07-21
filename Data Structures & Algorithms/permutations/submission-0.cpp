class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr={};
        int n=nums.size();
        vector<bool> vis(n,0);
        dfs(nums,curr,vis);
        return ans;
    }
    void dfs(vector<int>& nums,vector<int> &curr,vector<bool> &vis){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i]) continue;
            vis[i]=1;
            curr.push_back(nums[i]);
            dfs(nums,curr,vis);
            vis[i]=0;
            curr.pop_back();
        }
    }
};
