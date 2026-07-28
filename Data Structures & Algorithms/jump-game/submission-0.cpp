class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp(n,0);
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            bool temp=0;
            for(int j=i+1;j<=min(n-1,i+nums[i]);j++){
                temp=temp||dp[j];
            }
            dp[i]=temp;
        }
        return dp[0];
    }
};
