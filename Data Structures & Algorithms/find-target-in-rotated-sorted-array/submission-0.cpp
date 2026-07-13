class Solution {
public:
    int bs(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        // Find pivot (minimum element)
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[n - 1])
                l = mid + 1;
            else
                r = mid - 1;
        }

        int pivot = l;

        int ans = bs(nums, 0, pivot - 1, target);
        if (ans != -1)
            return ans;

        return bs(nums, pivot, n - 1, target);
    }
};