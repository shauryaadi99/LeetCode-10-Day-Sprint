class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int totsum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > totsum)
            return 0;

        if ((target + totsum) % 2 != 0)
            return 0;

        target = (target + totsum) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // Base case
        dp[0][0] = (nums[0] == 0 ? 2 : 1);

        // First element
        if (nums[0] != 0 && nums[0] <= target)
            dp[0][nums[0]] = 1;

        // Notice t starts from 0
        for (int i = 1; i < n; i++) {

            for (int t = 0; t <= target; t++) {

                int nottake = dp[i - 1][t];

                int take = 0;

                if (t >= nums[i]) {
                    take = dp[i - 1][t - nums[i]];
                }

                dp[i][t] = take + nottake;
            }
        }

        return dp[n - 1][target];
    }
};