class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int asc_count = 0, desc_count = 0;
        for (int i = 1; i < n; i++) {
            asc_count += (nums[i] == (nums[i - 1] + 1) % n);
            desc_count += (nums[i - 1] == (nums[i] + 1) % n);
        }
        if (asc_count == n - 1 && nums[0] == 0) {
            return 0;
        }
        if (asc_count == n - 1) {
            int left_rot = n - nums[0];
            int right_rot = 1 + nums.back() + 1 + 1;
            return min(left_rot, right_rot);
        }
        if (desc_count == n - 1) {
            int left_count = n - nums.back() + 1;
            int right_count = (nums[0] + 1) % n + 1;
            return min(left_count, right_count);
        }
        return -1;
    }
};