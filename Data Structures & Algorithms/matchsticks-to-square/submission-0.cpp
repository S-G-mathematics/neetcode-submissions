class Solution {
public:
    vector<int> sl;
    int esl;
    bool makesquare(vector<int>& matchsticks) {
        sl=vector<int>(4,0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0) return false;
        esl=sum/4;
        return dfs(matchsticks,0);
    }
    bool dfs(vector<int>& matchsticks,int idx){
        if(idx==matchsticks.size()){
            for(int i=0;i<4;i++){
                if(sl[i]!=esl)return false;
            }
            return true;
        }
        bool p=false;
        for(int i=0;i<4;i++){
            sl[i]=sl[i]+matchsticks[idx];
            if(sl[i]>esl)p=p||false;
            else{
                p=p||dfs(matchsticks,idx+1);
            }
            sl[i]=sl[i]-matchsticks[idx];
        }
        return p;
    }

};