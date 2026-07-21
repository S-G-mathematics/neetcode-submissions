class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> vis(n,0);
        vector<int> curr;
        dfs(nums,vis,curr);
        return ans;

    }
    void dfs(vector<int> &nums,vector<bool> &vis,vector<int> &curr){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i])continue;
            if(i>0 && nums[i]==nums[i-1] && !vis[i-1]) continue;
            vis[i]=1;
            curr.push_back(nums[i]);
            dfs(nums,vis,curr);
            curr.pop_back();
            vis[i]=false;
        }
    }
};