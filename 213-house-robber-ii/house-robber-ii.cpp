class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        if (n == 3)
            return max({nums[0], nums[1], nums[2]});
        int prev2 = nums[0], prev = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i++) {
            int curr = max(nums[i] + prev2, prev);
            prev2 = prev;
            prev = curr;
        }
        int a = prev;
        prev2 = nums[1], prev = max(nums[1], nums[2]);
        for (int i = 3; i < n; i++) {
            int curr = max(nums[i] + prev2, prev);
            prev2 = prev;
            prev = curr;
        }
        int b = prev;
        return max(a, b);
    }
};