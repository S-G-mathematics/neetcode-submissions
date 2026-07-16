class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);

        for (char c : s) {
            count[c - 'a']++;
        }

        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                pq.push({count[i], char('a' + i)});
            }
        }

        pair<int, char> wait = {0, '#'};

        string ans = "";

        while (!pq.empty()) {
            auto q = pq.top();
            pq.pop();

            ans += q.second;
            q.first--;

            if (wait.first > 0)
                pq.push(wait);

            wait = q;
        }

        if (ans.size() != s.size())
            return "";

        return ans;
    }
};