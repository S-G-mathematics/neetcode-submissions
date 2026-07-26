class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a=s1.size();
        int b=s2.size();
        int c=s3.size();
        if((a+b)!=c)return false;
        vector<vector<bool>> dp(a+1,vector<bool>(b+1,0));
        dp[a][b]=1;
        for(int i=a-1;i>=0;i--){
            dp[i][b]=dp[i+1][b];
            if(s3[c-(a-i)]!=s1[i])dp[i][b]=0;
        }
        for(int i=b-1;i>=0;i--){
            dp[a][i]=dp[a][i+1];
            if(s3[c-(b-i)]!=s2[i])dp[a][i]=0;
        }

        for(int i=a-1;i>=0;i--){
            for(int j=b-1;j>=0;j--){
                dp[i][j]=0;
                if(s1[i]==s3[i+j])dp[i][j]=dp[i+1][j] || dp[i][j];
                if(s2[j]==s3[j+i])dp[i][j]=dp[i][j+1] || dp[i][j];
            }
        }

        return dp[0][0];
    }
};
