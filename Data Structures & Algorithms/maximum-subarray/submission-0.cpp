class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx=nums[0];
        int cur=0;
        for(int n:nums){
            if(cur<0){
                cur=0;
            }
            cur=cur+n;
            mx=max(mx,cur);
        }
        return mx;
    }
};
