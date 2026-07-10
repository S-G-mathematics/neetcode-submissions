class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=nums[0];
        int cnt=1;
        int n=nums.size();
        if(n==1) return maj;
        for(int i=1;i<n;i++){
            if(nums[i]==maj){
                cnt++;
            }
            else if(nums[i]!=maj && cnt==0){
                maj=nums[i];
                cnt=1;
            }
            else{
                cnt--;
            }
        }
        return maj;
    }
};