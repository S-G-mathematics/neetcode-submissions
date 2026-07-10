class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        res.resize(n);
        int z=count(nums.begin(),nums.end(),0);
        if(z>1) return vector<int>(n,0);
        if(z==1){
            int product=1;
            int idx=0;
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    idx=i;
                }else product=product*nums[i];
            }
            for(int i=0;i<n;i++){
                if(i==idx)res[i]=product;
                else res[i]=0;
            }
        }

        if(z==0){
            int product=1;
            for(int i=0;i<n;i++){
                product=product*nums[i];
            }
            for(int i=0;i<n;i++){
                res[i]=product/nums[i];
            }
        }
        
        return res;
    }
};
