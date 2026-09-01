class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);
        if (sum & 1)
            return false;
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for (int t = 1; t <= target; t++) {
            dp[0][t] = (nums[0] == t);
        }
        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= target; t++) {
                int take = false, nottake;
                nottake = dp[i - 1][t];
                if (t >= nums[i]) {
                    take = dp[i - 1][t - nums[i]];
                }
                dp[i][t] = (take || nottake);
            }
        }
        return dp[n - 1][target];
    }
};