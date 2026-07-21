class Solution {
public:
    int ROWS, COLS;
    vector<vector<bool>> visited;

    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (dfs(r, c, 0, word, board, visited)) {   // FIX
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int r, int c, int idx,
             string &word,
             vector<vector<char>>& board,
             vector<vector<bool>>& vis) {

        if (idx == word.length())
            return true;

        // FIX: ROWS, COLS, idx, vis
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS ||
            board[r][c] != word[idx] || vis[r][c])
            return false;

        vis[r][c] = true;

        // FIX: correct arguments and directions
        bool res =
            dfs(r + 1, c, idx + 1, word, board, vis) ||
            dfs(r - 1, c, idx + 1, word, board, vis) ||
            dfs(r, c + 1, idx + 1, word, board, vis) ||
            dfs(r, c - 1, idx + 1, word, board, vis);

        vis[r][c] = false;

        return res;
    }
};