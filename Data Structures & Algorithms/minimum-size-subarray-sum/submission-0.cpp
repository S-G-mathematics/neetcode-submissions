class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        vector<int> temp={};
        int sum=0;
        int ans=1e9;
        for(int i=0;i<n;i++){
            temp.push_back(nums[i]);
            sum=sum+nums[i];
            while(sum>=target){
                ans=min(ans,(int)temp.size());
                int q=temp[0];
                temp.erase(temp.begin());
                sum=sum-q;
            } 
        }
        if(ans!=1e9)return ans;
        else return 0;
    }
};