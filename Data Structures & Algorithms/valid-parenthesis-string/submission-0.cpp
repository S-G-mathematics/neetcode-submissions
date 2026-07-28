class Solution {
public:
    bool checkValidString(string s) {
        int lmn=0;
        int lmx=0;
        for(char c:s){
            if(c=='('){
                lmn++;
                lmx++;
            }else if(c==')'){
                lmn--;
                lmx--;
            }else{
                lmn--;
                lmx++;
            }
            if(lmx<0) return false;
            if(lmn<0) lmn=0;
        }
        return lmn==0;
    }
};
