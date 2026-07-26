class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int a=sum+target;
        if(abs(target)>sum)return 0;
        if(a%2==1)return 0;
        a=a/2;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(a+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=a;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=nums[i-1]){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][a];
    }
};
