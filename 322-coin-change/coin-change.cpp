class Solution {
public:
    const int INF = 1e9;
    int t[13][10001];
    int solve(int i, int amount, vector<int>& coins) {

        if (amount == 0) {
            return 0;
        }

        if (i == 0) {
            if (amount % coins[0] == 0) {
                return amount / coins[0];
            }
            return INF;
        }
        if (t[i][amount] != -1)
            return t[i][amount];
        int take = INF;
        int nottake = solve(i - 1, amount, coins);
        if (coins[i] <= amount) {
            take = 1 + solve(i, amount - coins[i], coins);
        }
        return t[i][amount] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(t, -1, sizeof(t));
        int ans = solve(n - 1, amount, coins);
        return ans == INF ? -1 : ans;
    }
};