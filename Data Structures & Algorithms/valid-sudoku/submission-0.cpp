class Solution {
public:
    bool checkrow(vector<vector<char>>& board, int i) {
        unordered_set<char> s;

        for (char c : board[i]) {
            if (c == '.') continue;

            if (s.count(c))
                return false;

            s.insert(c);
        }

        return true;
    }

    bool checkcol(vector<vector<char>>& board, int j) {
        unordered_set<char> s;

        for (int i = 0; i < 9; i++) {
            char c = board[i][j];

            if (c == '.') continue;

            if (s.count(c))
                return false;

            s.insert(c);
        }

        return true;
    }

    bool checkbox(vector<vector<char>>& board, int row, int col) {
        unordered_set<char> s;

        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                char c = board[i][j];

                if (c == '.') continue;

                if (s.count(c))
                    return false;

                s.insert(c);
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        // Check all rows
        for (int i = 0; i < 9; i++) {
            if (!checkrow(board, i))
                return false;
        }

        // Check all columns
        for (int j = 0; j < 9; j++) {
            if (!checkcol(board, j))
                return false;
        }

        // Check all 3x3 boxes
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!checkbox(board, i, j))
                    return false;
            }
        }

        return true;
    }
};