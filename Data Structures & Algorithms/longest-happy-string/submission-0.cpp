class Solution {
public:
    int getMax(const vector<int> &count,int repeated){
        int idx=-1;int mx=0;
        for(int i=0;i<3;i++){
            if(i==repeated || count[i]==0) continue;
            if(mx<count[i]){
                mx=count[i];
                idx=i;
            }
        }
        return idx;
    }
    string longestDiverseString(int a, int b, int c) {
        vector<int> count={a,b,c};
        string ans="";
        int rep=-1;
        while(true){
            int mc=getMax(count,rep);
            if(mc==-1){
                break;
            }
            ans=ans+(char)(mc+'a');
            count[mc]--;

            if(ans.size()>1 && ans.back()==ans[ans.size()-2]){
                rep=mc;
            }else{
                rep=-1;
            }
        }
        return ans;
    }
};