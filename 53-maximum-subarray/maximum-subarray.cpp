class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currsum = 0, globalsum = INT_MIN;
        for (int i = 0; i < n; i++) {
            currsum = max(nums[i], currsum + nums[i]);
            globalsum = max(globalsum, currsum);
        }
        return globalsum;
    }
};