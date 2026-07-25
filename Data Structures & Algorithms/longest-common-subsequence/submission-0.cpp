class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int a=text1.size();
        int b=text2.size();
        vector<vector<int>> dp(a+1,vector<int>(b+1,0));
        dp[a][b]=0;
        for(int i=0;i<a;i++){
            dp[i][b]=0;
        }
        for(int i=0;i<b;i++){
            dp[a][i]=0;
        }
        for(int i=a-1;i>=0;i--){
            for(int j=b-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }else{
                    dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
};
