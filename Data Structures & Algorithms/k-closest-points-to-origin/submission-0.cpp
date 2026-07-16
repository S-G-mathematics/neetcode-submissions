class Solution {
public:
    int ds(int x,int y){
        return x*x+y*y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=points.size();
        for(int i=0;i<n;i++){
            int dis=ds(points[i][0],points[i][1]);
            pq.push({dis,i});
        }
        int temp=k;
        vector<vector<int>> ans;
        while(k--){
            pair<int,int> q=pq.top();
            pq.pop();
            ans.push_back(points[q.second]);
        }
        return ans;
    }
};
