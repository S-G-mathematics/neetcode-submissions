class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0;
        int r=0;
        int n=nums.size();
        while(r<n){
            nums[l]=nums[r];
            while(r<n && nums[r]==nums[l]){
                r++;
            }
            l++;
        }
        return l;
    }
};