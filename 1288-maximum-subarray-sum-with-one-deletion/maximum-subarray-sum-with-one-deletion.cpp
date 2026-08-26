class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int k = 1;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, INT_MIN));
        for (int j = 0; j <= k; j++) {
            dp[0][j] = arr[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                int x = max(arr[i], arr[i] + dp[i - 1][j]);
                int y = INT_MIN;
                if (j > 0) {
                    y = dp[i - 1][j - 1];
                }
                dp[i][j] = max(x, y);
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[i][k]);
        return ans;
    }
};