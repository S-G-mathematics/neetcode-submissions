class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n=arr.size();
        vector<int> result(n);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            if(st.empty())st.push({i,arr[i]});
            else{
            while(!st.empty() && st.top().second<arr[i]){
                pair<int,int> q=st.top();
                st.pop();
                result[q.first]=i-q.first;
            }
            st.push({i,arr[i]});
        }}
        while(!st.empty()){
            result[st.top().first]=0;
            st.pop();
        }
        return result;

    }
};
