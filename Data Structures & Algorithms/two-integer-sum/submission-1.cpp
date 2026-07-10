class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s[target-nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(s.find(nums[i])!=s.end() && i!=s.find(nums[i])->second ) return {i,s.find(nums[i])->second};
        }

    }
};
