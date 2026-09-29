class Solution {
public:
    bool dp[101][101][201];

    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Path length must be even
        if ((n + m - 1) % 2 != 0)
            return false;

        memset(dp, false, sizeof(dp));

        // Starting cell must be '('
        if (grid[0][0] == '(')
            dp[0][0][1] = true;
        else
            return false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i == 0 && j == 0)
                    continue;

                for (int balance = 0; balance <= n + m; balance++) {

                    int newBalance;

                    if (grid[i][j] == '(')
                        newBalance = balance + 1;
                    else
                        newBalance = balance - 1;

                    if (newBalance < 0)
                        continue;

                    // Come from above
                    if (i > 0)
                        dp[i][j][newBalance] |= dp[i - 1][j][balance];

                    // Come from left
                    if (j > 0)
                        dp[i][j][newBalance] |= dp[i][j - 1][balance];
                }
            }
        }

        return dp[n - 1][m - 1][0];
    }
};