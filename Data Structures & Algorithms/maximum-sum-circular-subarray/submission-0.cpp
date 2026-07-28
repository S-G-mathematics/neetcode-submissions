class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int gmx=nums[0];
        int gmn=nums[0];
        int curmax=0;
        int curmin=0;
        int tot=0;
        for(int n:nums){
            curmax=max(curmax+n,n);
            curmin=min(curmin+n,n);
            tot+=n;
            gmx=max(gmx,curmax);
            gmn=min(gmn,curmin);
        }

        return gmx>0?max(gmx,tot-gmn):gmx;
    }
};