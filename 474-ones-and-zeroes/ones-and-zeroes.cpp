class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        // dp[z][o] = maximum number of strings
        // we can select using at most z zeros and o ones.
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string &s : strs) {

            int zeros = 0;
            int ones = 0;

            for (char c : s) {
                if (c == '0')
                    zeros++;
                else
                    ones++;
            }

            // Reverse traversal -> 0/1 knapsack
            for (int z = m; z >= zeros; z--) {

                for (int o = n; o >= ones; o--) {

                    dp[z][o] = max(
                        dp[z][o],
                        1 + dp[z - zeros][o - ones]
                    );
                }
            }
        }

        return dp[m][n];
    }
};