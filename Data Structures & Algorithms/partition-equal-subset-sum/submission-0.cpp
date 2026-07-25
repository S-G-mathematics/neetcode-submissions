class Solution {
public:
    bool whynot(vector<int> &nums,int sum){
        int n=nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=nums[i-1]){
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i][j];
                    }
            }
        }
        return dp[n][sum];
    }


    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1)return false;
        int n=nums.size();
        return whynot(nums,sum/2);
    }
};
