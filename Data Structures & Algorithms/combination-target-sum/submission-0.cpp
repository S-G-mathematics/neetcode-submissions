class Solution {
public:
vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cura={};
        dfs(nums,target,cura,0,0);
        return ans;
    }
    void dfs(vector<int>& nums,int target,vector<int> &cura,int idx,int curr){
        if(curr>target)return;
        if(curr==target){
            ans.push_back(cura);
            return;
        }
        if(idx==nums.size())return;
        cura.push_back(nums[idx]);
        curr=curr+nums[idx];
        dfs(nums,target,cura,idx,curr);
        cura.pop_back();
        curr=curr-nums[idx];
        dfs(nums,target,cura,idx+1,curr);
    }
};
