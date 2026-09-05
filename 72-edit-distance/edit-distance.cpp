class Solution {
public:
    int t[501][501];
    int solve(int i, int j, string& word1, string& word2) {
        if (i < 0)
            return j + 1;

        if (j < 0)
            return i + 1;

        if (t[i][j] != -1)
            return t[i][j];

        if (word1[i] == word2[j])
            return t[i][j] = solve(i - 1, j - 1, word1, word2);

        // word1 ---> word2
        int del = 1 + solve(i - 1, j, word1, word2);
        int insert = 1 + solve(i, j - 1, word1, word2);
        int replace = 1 + solve(i - 1, j - 1, word1, word2);

        return t[i][j] = min({del, insert, replace});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // memset(t, -1, sizeof(t));
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                    continue;
                }
                int del = 1 + dp[i - 1][j];
                int ins = 1 + dp[i][j - 1];
                int repl = 1 + dp[i - 1][j - 1];
                dp[i][j] = min({del, ins, repl});
            }
        }
        return dp[n][m];
    }
};
// Time  = O(n × m)
// Space = O(n × m)