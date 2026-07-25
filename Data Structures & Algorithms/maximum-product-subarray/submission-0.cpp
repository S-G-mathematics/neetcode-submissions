class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int curmin=1;
        int curmax=1;
        for(int n:nums){
            int temp=curmax*n;
            curmax=max(max(curmax*n,curmin*n),n);
            curmin=min(min(temp,curmin*n),n);
            res=max(curmax,res);
        }
        return res;
    }
};
