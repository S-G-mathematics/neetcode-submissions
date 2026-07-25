class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[n]=true;
        for(int i=n;i>=0;i--){
            for(string t:wordDict){
                if (i+t.size()<=n && s.substr(i, t.size()) == t){
                    dp[i]=dp[i+t.size()];
                }if(dp[i]==true)break;
            }
        }
        return dp[0];
    }
};
