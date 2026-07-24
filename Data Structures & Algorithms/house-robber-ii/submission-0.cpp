class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        if(n==3)return max(max(nums[0],nums[1]),nums[2]);
        vector<int> nums1(nums.begin(),nums.end()-1);
        vector<int> nums2(nums.begin()+1,nums.end());
        vector<int> dp(n-1);
        dp[0]=nums1[0];
        dp[1]=max(nums1[0],nums1[1]);
        for(int i=2;i<n-1;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums1[i]);
        }
        vector<int> qp(n-1);
        qp[0]=nums2[0];
        qp[1]=max(nums2[0],nums2[1]);
        for(int i=2;i<n-1;i++){
            qp[i]=max(qp[i-1],qp[i-2]+nums2[i]);
        }
        return max(dp[n-2],qp[n-2]);
    }
};
