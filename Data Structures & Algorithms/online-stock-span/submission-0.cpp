class StockSpanner {
private:
    vector<int> prices;
    vector<int> span;
    stack<int> st;

public:
    StockSpanner() {
    }

    int next(int price) {
        prices.push_back(price);
        int n = prices.size();

        int ans = 1;

        while (!st.empty() && prices[st.top()] <= price) {
            ans += span[st.top()];
            st.pop();
        }

        span.push_back(ans);
        st.push(n - 1);

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */