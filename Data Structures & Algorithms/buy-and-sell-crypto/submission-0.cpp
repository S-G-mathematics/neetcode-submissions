class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int n=prices.size();
     int ans=0;
     for(int i=0;i<n-1;i++){
        int mx = *max_element(prices.begin()+i+1, prices.end());
        ans=max(ans,mx-prices[i]);
     }
     return ans;
    }
};
