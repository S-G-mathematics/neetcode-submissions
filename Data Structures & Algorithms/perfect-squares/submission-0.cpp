class Solution {
public:
    int numSquares(int n) {
        int t=sqrt(n);
        vector<int> ps(t);
        for(int i=0;i<t;i++){
            ps[i]=(i+1)*(i+1);
        }
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=t-1;j>=0;j--){
                if(ps[j]<=i){
                    dp[i]=min(dp[i],dp[i-ps[j]]+1);
                }
            }
        }
        return dp[n];
    }
};