class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: 2 piles
        for (int i = 0; i + 1 < n; i++) {
            dp[i][i + 1] = abs(piles[i] - piles[i + 1]);
        }

        // len = number of piles in current interval
        for (int len = 4; len <= n; len += 2) {
            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                int left1 = (piles[i] - piles[i + 1]) + dp[i + 2][j];
                int left2 = (piles[i] - piles[j]) + dp[i + 1][j - 1];
                int left = min(left1, left2);

                int right1 = (piles[j] - piles[i]) + dp[i + 1][j - 1];
                int right2 = (piles[j] - piles[j - 1]) + dp[i][j - 2];
                int right = min(right1, right2);

                dp[i][j] = max(left, right);
            }
        }

        return dp[0][n - 1] > 0;
    }
};