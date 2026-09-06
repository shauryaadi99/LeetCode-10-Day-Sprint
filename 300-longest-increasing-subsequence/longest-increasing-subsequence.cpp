class Solution {
public:
    int t[2501][2501];
    int solve(int i, int prev_idx, vector<int>& nums) {
        if (i < 0)
            return 0;
        int len;
        if (t[i][prev_idx + 1] != -1)
            return t[i][prev_idx + 1];

        len = 0 + solve(i - 1, prev_idx, nums);
        if (prev_idx == -1 || nums[i] < nums[prev_idx]) {
            int x = 1 + solve(i - 1, i, nums);
            len = max(len, x);
        }
        return t[i][prev_idx + 1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(n - 1, -1, nums);
    }
};