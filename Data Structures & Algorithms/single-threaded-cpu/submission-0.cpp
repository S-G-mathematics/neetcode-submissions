class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> enq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> proc;
        int n=tasks.size();
        for(int i=0;i<n;i++){
            enq.push({tasks[i][0],i});
        }
        int t=0;
        vector<int> ans;
        while(!enq.empty() || !proc.empty()){
            t++;
            while(!enq.empty() && enq.top().first<=t){
                auto q=enq.top();
                int i=q.second;
                enq.pop();
                proc.push({tasks[i][1],i});
            }
            if(!proc.empty()){
            auto l=proc.top();
            ans.push_back(l.second);
            proc.pop();
            t=t+l.first-1;
            }
        }
        return ans;
    }
};