class Solution {
public:
    vector<int> nums;
    int n;
    int target;
    int firstOccurances() {
        int first = -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                first = mid;
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return first;
    }
    int lastOccurances() {
        int last = -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                last = mid;
                l = mid + 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        this->nums = nums;
        this->n = nums.size();
        this->target = target;
        if (firstOccurances() == -1) {
            return {-1, -1};
        }
        return {firstOccurances(), lastOccurances()};
    }
};