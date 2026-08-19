class Solution {
public:
    int target;
    int n;
    int lower_bound(vector<int>& nums) {
        int low = 0, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        if (low == n || nums[low] != target)
            return -1;
        return low;
    }
    int upper_bound(vector<int>& nums) {
        int low = 0, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        this->n = nums.size();
        this->target = target;
        // this->nums = nums;
        int first_Occur = lower_bound(nums);
        if (first_Occur == -1) {
            return {-1, -1};
        }
        int last_Occur = upper_bound(nums) - 1;
        return {first_Occur, last_Occur};
    }
};