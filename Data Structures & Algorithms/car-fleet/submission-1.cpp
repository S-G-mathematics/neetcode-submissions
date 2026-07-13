class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int,int>> ps;
        for (int i = 0; i < n; i++) {
            ps.push_back({position[i], speed[i]});
        }

        sort(ps.begin(), ps.end(), greater<pair<int,int>>());

        stack<double> st;

        for (int i = 0; i < n; i++) {
            double time = (double)(target - ps[i].first) / ps[i].second;

            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }

        return st.size();
    }
};