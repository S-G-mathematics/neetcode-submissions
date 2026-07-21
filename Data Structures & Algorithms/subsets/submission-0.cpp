class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr={};
        dfs(nums,curr,0);
        return ans;
    }
    void dfs(vector<int>& nums,vector<int> &curr,int idx){
        if(idx==nums.size()){
        ans.push_back(curr);
        return;
        }
        curr.push_back(nums[idx]);
        dfs(nums,curr,idx+1);
        curr.pop_back();
        dfs(nums,curr,idx+1);
    }

};
