class Solution {
public:
    int ans=0;
    int subsetXORSum(vector<int>& nums) {
        dfs(nums,0,0);
        return ans;
    }
    void dfs(vector<int> &nums,int idx,int curr){
        if(idx==nums.size()){
            ans=ans+curr;
            return;
        }
        dfs(nums,idx+1,curr^nums[idx]);
        dfs(nums,idx+1,curr);
    }
};