class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        if(n<0) return 1/myPow(x,-1*n);
        if(n%2==1)return myPow(x,n-1)*x;
        double t=myPow(x,n/2);
        return t*t;
    }
};
