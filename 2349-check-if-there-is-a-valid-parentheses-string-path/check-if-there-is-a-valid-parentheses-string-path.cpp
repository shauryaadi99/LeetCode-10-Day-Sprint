class Solution {
public:
    int dp[101][101][201];
    bool solve(int i, int j, int balance, vector<vector<char>>& grid) {
        // left or up
        bool up = false, left = false;
        if (i < 0 || j < 0)
            return false;
        if (grid[i][j] == '(')
            balance--;
        else
            balance++;
        if (balance < 0)
            return false;
        if (i == 0 && j == 0)
            return (balance == 0);
        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];
        if (i - 1 >= 0)
            up = solve(i - 1, j, balance, grid);
        if (j - 1 >= 0)
            left = solve(i, j - 1, balance, grid);
        return dp[i][j][balance] = (up || left);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(n - 1, m - 1, 0, grid);
    }
};