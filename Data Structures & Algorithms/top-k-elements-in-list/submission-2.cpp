class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int x : nums)
            freq[x]++;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > minheap;

        for (auto &q : freq) {
            minheap.push({q.second, q.first});

            if (minheap.size() > k)
                minheap.pop();
        }

        vector<int> res;

        while (!minheap.empty()) {
            res.push_back(minheap.top().second);
            minheap.pop();
        }

        return res;
    }
};