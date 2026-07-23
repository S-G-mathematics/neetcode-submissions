class Solution {
public:
    int get(int x){
        int cnt=0;
        while(x){
            cnt+=(x&1);
            x=x>>1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(get(i));
        }
        return ans;
    }
};
