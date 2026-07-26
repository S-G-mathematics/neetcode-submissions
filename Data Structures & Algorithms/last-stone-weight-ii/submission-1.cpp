class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=accumulate(stones.begin(),stones.end(),0);
        int t=sum/2;
        int n=stones.size();
        vector<vector<bool>> dp(n+1,vector<bool>(t+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=t;j++){
                dp[i][j]=dp[i-1][j];
                if(stones[i-1]<=j){
                    dp[i][j]=dp[i][j]||dp[i-1][j-stones[i-1]];
                }
            }
        }
        for(int j=t;j>=0;j--){
            if(dp[n][j])return abs(sum-2*j);
        }
    return 0;
        
    }
};