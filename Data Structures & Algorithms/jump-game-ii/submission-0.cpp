class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--) {
            int best = INT_MAX;

            for (int j = i + 1; j <= min(n - 1, i + nums[i]); j++) {
                best = min(best, dp[j]);
            }

            if (best != INT_MAX)
                dp[i] = best + 1;
        }

        return dp[0];
    }
};