class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        int ans=1;
        for(int i=0;i<n;i++){
            int el=nums[i];
            int temp=1;
            while(find(nums.begin(),nums.end(),el+1)!=nums.end()){
                temp++;
                el++;
            }
        ans=max(ans,temp);
        }
        return ans;
    }
};
