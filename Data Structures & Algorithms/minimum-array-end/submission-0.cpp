class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long k = n - 1;

        for (int i = 0; i < 63; i++) {
            if ((ans & (1LL << i)) == 0) {
                if (k & 1)
                    ans |= (1LL << i);
                k >>= 1;
            }
        }

        return ans;
    }
};