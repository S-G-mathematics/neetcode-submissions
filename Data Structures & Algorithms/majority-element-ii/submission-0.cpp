class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq;
        for(int l:nums){
            freq[l]++;
        }
        vector<int> res;
        for(auto &p:freq){
            if(p.second>n/3){
                res.push_back(p.first);
            }
        }
        return res;
    }
};