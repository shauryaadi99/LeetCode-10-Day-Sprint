class Solution {
public:
    vector<int> arr;
    int solve(int i, int j, vector<vector<int>>& dp) {
        if (i == 0) {
            return arr[0];
        }
        if (dp[i][j] != INT_MIN)
            return dp[i][j];
        // take
        int x = max(arr[i], arr[i] + solve(i - 1, j, dp));
        // not-take
        int y = INT_MIN;
        if (j > 0)
            y = solve(i - 1, j - 1, dp);
        dp[i][j] = max(x, y);
        return dp[i][j];
    }
    int maximumSum(vector<int>& arr) {
        int n = arr.size(), k = 1;
        this->arr = arr;
        vector<vector<int>> dp(n, vector<int>(k + 1, INT_MIN));
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, k, dp));
        }
        return ans;
    }
};