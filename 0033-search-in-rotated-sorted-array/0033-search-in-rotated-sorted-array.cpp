class Solution {
    int find_rotate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;

        while (l < r) {
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }

    int binarysearch(vector<int>& nums, int target, int l, int r) {
        int low = l;
        int high = r;
        int mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }

   public:
    int search(vector<int>& nums, int target) {
        int index_part = find_rotate(nums);

        // cout << index_part << endl;

        int idx_1 = binarysearch(nums, target, 0, index_part);

        // cout << idx_1 << endl;

        int idx_2 = binarysearch(nums, target, index_part, nums.size() - 1);

        // cout << idx_2 << endl;
        return max(idx_1, idx_2);
    }
};
