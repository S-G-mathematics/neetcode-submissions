class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),[](const vector<int> &a,const vector<int> &b){return a[1]<b[1];});
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> mh;
        int curr=0;
        for(auto &trip :trips){
            int n=trip[0];
            int st=trip[1];
            int end=trip[2];
            while(!mh.empty() && mh.top().first<=st){
                curr=curr-mh.top().second;
                mh.pop();
            }
            curr=curr+n;
            if(curr>capacity) return false;
            mh.emplace(end,n);
        }
        return true;
    }
};