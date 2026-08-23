class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int currMin = 0, currMax = 0, totSum = 0, globalMin = nums[0],
            globalMax = nums[0];
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            totSum += x;
            currMin = min(x, currMin + x);
            currMax = max(x, currMax + x);
            globalMin = min(globalMin, currMin);
            globalMax = max(globalMax, currMax);
        }
        if (globalMax < 0)
            return globalMax;
        return max(globalMax, totSum - globalMin);
    }
};