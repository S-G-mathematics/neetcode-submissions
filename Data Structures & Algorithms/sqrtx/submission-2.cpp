class Solution {
public:
    int mySqrt(int x) {
        int l=0;
        int r=x;
        int ans;
        while(l<=r){
            int mid=l+(r-l)/2;
            long long sq=1LL*mid*mid;
            if(sq==x)return mid;
            else if(sq<x){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};