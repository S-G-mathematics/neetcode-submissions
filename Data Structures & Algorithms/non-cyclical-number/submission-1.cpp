class Solution {
public:
    bool isHappy(int n) {
        if(n==1 || n==7)return true;
        if(n>=2 && n<=9) return false;
        if(n==58 || n==85 || n==37 || n==89)return false;
        if(n==16 || n==25 || n==36 || n==49 || n==64 || n==81)return false;
        int q=0;
        int temp=n;
        while(temp){
            q=q+(temp%10)*(temp%10);
            temp=temp/10;
        }
        return isHappy(q);
    }
};
