class Solution {
public:
    // const int INF = 1e9;
    // int solve(int i, int amount, vector<int>& coins) {
    //     if (amount == 0) {
    //         return 1;
    //     }
    //     if (i == 0) {
    //         return (amount % coins[0] == 0 ? 1 : 0);
    //     }
    //     int take = 0;
    //     int nottake = solve(i - 1, amount, coins);
    //     if (coins[i] <= amount)
    //         take = solve(i, amount - coins[i], coins);
    //     return (take + nottake);
    // }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = 1;
        for (int a = 0; a <= amount; a++) {
            dp[0][a] = (a % coins[0] == 0 ? 1 : 0);
        }
        for (int i = 1; i < n; i++) {
            for (int a = 0; a <= amount; a++) {
                long long take = 0;
                long long nottake = dp[i - 1][a];
                if (coins[i] <= a)
                    take = dp[i][a - coins[i]];
                if (take > INT_MAX - nottake)
                    dp[i][a] = INT_MAX;
                else
                    dp[i][a] = take + nottake;
            }
        }
        // return solve(n - 1, amount, coins);
        return dp[n - 1][amount];
    }
};