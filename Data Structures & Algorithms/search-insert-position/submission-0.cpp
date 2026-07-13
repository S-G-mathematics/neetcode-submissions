class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target)return mid;
            else if(mid!=n-1 && nums[mid]<target && nums[mid+1]>target) return mid+1;
            else if(mid!=0 && nums[mid-1]<target && nums[mid]>target) return mid;
            else if(mid==n-1 && target>nums[mid])return n;
            else if(mid==0 && target<nums[mid]) return 0;
            else if(nums[mid]<target) l=mid+1;
            else if(nums[mid]>target) r=mid-1;
        }
        return 0;
    }
};