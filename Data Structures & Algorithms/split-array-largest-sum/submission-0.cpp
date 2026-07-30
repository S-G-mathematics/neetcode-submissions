class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        int res=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(c(nums,k,mid)){
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
    bool c(vector<int>& nums,int k,int largest){
        int s=1;
        int cur=0;
        for(int n:nums){
            cur=cur+n;
            if(cur>largest){
                s++;
                if(s>k)return 0;
                cur=n;
            }
        }
        return true;
    }
};