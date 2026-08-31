class Solution {
public:
    const int INF = 1e9;
    int t[501][501];
    int solve(int i, int remain, vector<int>& cost, vector<int>& time, int n) {
        if (remain <= 0) {
            return 0;
        }

        if (i >= n) {
            return INF;
        }
        if (t[i][remain] != -1)
            return t[i][remain];
        int take, nottake;
        take = cost[i] + solve(i + 1, remain - 1 - time[i], cost, time, n);
        nottake = solve(i + 1, remain, cost, time, n);
        return t[i][remain] = min(take, nottake);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        for (int remain = 1; remain <= n; remain++) {
            dp[n][remain] = INF;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int remain = 1; remain <= n; remain++) {
                int newremain = max(0, remain - 1 - time[i]);
                int take = cost[i] + dp[i + 1][newremain];
                int nottake = dp[i + 1][remain];
                dp[i][remain] = min(take, nottake);
            }
        }
        // memset(t, -1, sizeof(t));
        // return solve(0, n, cost, time, n);
        return dp[0][n];
    }
};