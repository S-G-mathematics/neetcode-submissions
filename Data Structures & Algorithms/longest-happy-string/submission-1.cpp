class Solution {
public:
    int gm(const vector<int> &count, int rep){
        int idx=-1; int mx=0;
        for(int i=0;i<3;i++){
            if(rep==i || count[i]==0)continue;
            if(count[i]>mx){
                mx=count[i];
                idx=i;
            }
        }
        return idx;
    }
    string longestDiverseString(int a, int b, int c) {
        vector<int> count={a,b,c};
        int rep=-1;
        string ans="";
        while(true){
            int mc=gm(count,rep);
            if(mc==-1) break;
            ans=ans+(char)(mc+'a');
            count[mc]--;
            if(ans.size()>1 && ans.back()==ans[ans.size()-2])rep=mc;
            else rep=-1;
            }
        return ans;
    }
};