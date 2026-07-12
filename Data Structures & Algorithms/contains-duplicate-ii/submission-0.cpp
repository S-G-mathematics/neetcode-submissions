class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>=n-1){
            unordered_set<int> k(nums.begin(),nums.end());
            return nums.size()-k.size();
        } 
        unordered_map<int,int> freq;
        for(int i=0;i<=k;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]>1) return true;
        }
        for(int i=k+1;i<n;i++){
            freq[nums[i]]++;
            freq[nums[i-k-1]]--;
            if(freq[nums[i]]>1) return true;
        } 
        return false;
    }
};