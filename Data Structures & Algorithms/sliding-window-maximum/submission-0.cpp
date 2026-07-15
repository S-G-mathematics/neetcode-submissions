class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i++){
            pq.push({nums[i],i});
        }
        int n=nums.size();
        vector<int> ma;
        ma.push_back(pq.top().first);
        for(int i=k;i<n;i++){
            pq.push({nums[i],i});
            while(!pq.empty() && pq.top().second<i-k+1){
                pq.pop();
            }
            ma.push_back(pq.top().first);
        }
        return ma;
    }
};
