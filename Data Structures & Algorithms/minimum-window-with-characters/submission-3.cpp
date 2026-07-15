class Solution {
public:
    bool yes(vector<int>&tf,vector<int>&sf){
            for(int i=0;i<128;i++){
                if(tf[i]>sf[i])return false;
            }
            return true;
        }
    string minWindow(string s, string t) {
        int a=s.size();
        int b=t.size();
        if(a<b)return "";
        if(a==b && s==t)return s;
        vector<int> sf(128,0);
        vector<int> tf(128,0);
        for(char c:t){
            tf[c]++;
        }
        int l=0;
        int bs=0;
        int bl=INT_MAX;
        for(int r=0;r<a;r++){
            sf[s[r]]++;
            while(yes(tf,sf)){
                if(r-l+1<bl){
                    bl=r-l+1;
                    bs=l;
                }
                sf[s[l]]--;
                l++;
            }
        }
        if(bl==INT_MAX)return "";
        return s.substr(bs,bl);
    }
};
