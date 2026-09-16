class Solution {
public:
    const int mod = 1e9 + 7;
    int t[1001][1001];
    int solve(int n, int k, int i) {
        if (k == 0)
            return 1;
        if (i >= n)
            return 0;
        if (t[i][k] != -1)
            return t[i][k];

        int nottake = solve(n, k, i + 1);
        long long take = 0;
        for (int j = i + 1; j < n; j++) {
            take += (solve(n, k - 1, j) % mod);
        }
        return t[i][k] = (take + nottake) % mod;
    }
    int numberOfSets(int n, int k) {
        // memset(t, -1, sizeof(t));
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        
        for(int j=1;j<=k;j++){
            long long take = 0;
            for(int i=1;i<n;i++){
                take = (take + dp[i-1][j-1])%mod;
                int nottake = dp[i-1][j];
                dp[i][j] = (take + nottake)%mod;
            }
        }
        // return solve(n, k, 0);
        return dp[n - 1][k];
    }
};