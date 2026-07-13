class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        unordered_map<char, int> count;
        int l = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {
            count[s[r]]++;
            ans = max(ans, count[s[r]]);

            while (r - l + 1 - ans > k) {
                count[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};