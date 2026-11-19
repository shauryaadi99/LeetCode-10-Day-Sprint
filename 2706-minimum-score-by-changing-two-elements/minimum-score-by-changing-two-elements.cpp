class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int high = 0;
        // case 1
        high = nums[n - 2] - nums[1];
        high = min(nums[n-3] - nums[0],high);
        high = min(high, nums[n - 1] - nums[2]);
        return high;
    }
};