class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> cura;
        dfs(candidates, target, cura, 0, 0);

        return ans;
    }

    void dfs(vector<int>& candidates, int target,
             vector<int>& cura, int curr, int idx) {

        if (curr > target) return;

        if (curr == target) {
            ans.push_back(cura);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            cura.push_back(candidates[i]);

            dfs(candidates, target, cura, curr + candidates[i], i + 1);

            cura.pop_back();
        }
    }
};