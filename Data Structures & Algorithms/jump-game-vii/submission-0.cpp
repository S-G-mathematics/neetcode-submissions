class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        vector<bool> dp(n,0);
        dp[n-1]=1;
        if(n==1)return true;
        for(int i=n-2;i>=0;i--){
            bool temp=0;
            if(i+minJump>n-1){
                dp[i]=0;
                continue;
            }
            else{
                for(int j=i+minJump;j<=min(n-1,i+maxJump);j++){
                    temp=temp ||(s[j]=='0' && dp[j]);
                }
            }
            dp[i]=temp;
        }
        return dp[0];
    }
};