class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        if (n < 3) return ans;

        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Since array is sorted, no need to continue
            if (nums[i] > 0) break;

            int b = i + 1;
            int c = n - 1;

            while (b < c) {
                int sum = nums[i] + nums[b] + nums[c];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[b], nums[c]});

                    b++;
                    c--;

                    // Skip duplicates for second element
                    while (b < c && nums[b] == nums[b - 1]) b++;

                    // Skip duplicates for third element
                    while (b < c && nums[c] == nums[c + 1]) c--;
                }
                else if (sum < 0) {
                    b++;
                }
                else {
                    c--;
                }
            }
        }

        return ans;
    }
};