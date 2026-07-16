/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int bs(int target, MountainArray &mountainArr, int st, int end, bool asc) {
        int l = st;
        int r = end;

        if (asc) {
            while (l <= r) {
                int m = l + (r - l) / 2;
                int t = mountainArr.get(m);

                if (t == target) return m;
                else if (t < target) l = m + 1;
                else r = m - 1;
            }
        } else {
            while (l <= r) {
                int m = l + (r - l) / 2;
                int t = mountainArr.get(m);

                if (t == target) return m;
                else if (t > target) l = m + 1;
                else r = m - 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {

        int n = mountainArr.length();

        // Find Peak
        int l = 0, r = n - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (mountainArr.get(m) < mountainArr.get(m + 1))
                l = m + 1;
            else
                r = m;
        }

        int peak = l;

        int ans = bs(target, mountainArr, 0, peak, true);

        if (ans != -1)
            return ans;

        return bs(target, mountainArr, peak + 1, n - 1, false);
    }
};