class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> cnt;

    CountSquares() {
        
    }

    void add(vector<int> point) {
        cnt[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        for (auto &[ny, freq] : cnt[x]) {
            if (ny == y) continue;

            int side = ny - y;

            // Right square
            ans += freq * cnt[x + side][y] * cnt[x + side][ny];

            // Left square
            ans += freq * cnt[x - side][y] * cnt[x - side][ny];
        }

        return ans;
    }
};

/**
 * Your CountSquares object will be instantiated and called as such:
 * CountSquares* obj = new CountSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */