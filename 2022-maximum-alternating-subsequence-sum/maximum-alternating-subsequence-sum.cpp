class Solution {
public:
    long long solve(int idx, bool flag, vector<int>& nums,
              vector<vector<long long>>& dp) {
        if (idx == nums.size())
            return 0;
        long long take, nottake;
        if (dp[idx][flag] != -1) {
            return dp[idx][flag];
        }
        nottake = solve(idx + 1, flag, nums, dp);
        if (flag) {
            take = nums[idx] + solve(idx + 1, !flag, nums, dp);
        } else {
            take = -1 * nums[idx] + solve(idx + 1, !flag, nums, dp);
        }
        return dp[idx][flag] = max(take, nottake);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));

        return solve(0, true, nums, dp);
    }
};