class Solution {
public:
    int getSum(int a, int b) {
        int ans=0;
        int carry=0;
        do{
            ans=a^b;
            carry=(a&b)<<1;
            a=ans;
            b=carry;
        }while(carry);
        return ans;
    }
};
