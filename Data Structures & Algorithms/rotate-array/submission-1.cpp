class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k %= n;

        while (k--) {
            int last = arr[n - 1];

            for (int j = n - 1; j > 0; j--) {
                arr[j] = arr[j - 1];
            }

            arr[0] = last;
        }
    }
};