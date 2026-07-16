class Solution {
public:
    int getKth(vector<int>& a, vector<int>& b, int k, int m, int n, int as, int bs) {
        if (m > n)
            return getKth(b, a, k, n, m, bs, as);

        if (m == 0)
            return b[bs + k - 1];

        if (k == 1)
            return min(a[as], b[bs]);

        int i = min(k / 2, m);
        int j = min(k / 2, n);

        if (a[as + i - 1] > b[bs + j - 1]) {
            return getKth(a, b, k - j, m, n - j, as, bs + j);
        } else {
            return getKth(a, b, k - i, m - i, n, as + i, bs);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l = (nums1.size() + nums2.size() + 1) / 2;
        int r = (nums1.size() + nums2.size() + 2) / 2;

        return (getKth(nums1, nums2, l, nums1.size(), nums2.size(), 0, 0) +
                getKth(nums1, nums2, r, nums1.size(), nums2.size(), 0, 0)) / 2.0;
    }
};