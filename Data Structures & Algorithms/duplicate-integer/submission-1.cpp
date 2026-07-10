class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto q:nums){
            s.insert(q);
        }
        return nums.size()-s.size();
    }
};