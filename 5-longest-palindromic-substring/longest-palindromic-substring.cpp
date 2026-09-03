class Solution {
public:
    // int t[1001][1001];
    // bool solve(string& s, int i, int j) {
    //     if (i >= j)
    //         return t[i][j] = true;

    //     if (t[i][j] != -1)
    //         return t[i][j];

    //     if (s[i] == s[j]) {
    //         return t[i][j] = solve(s, i + 1, j - 1);
    //     }
    //     return t[i][j] = false;
    // }
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 1, sp = 0;
        // memset(t, -1, sizeof(t));
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                if (len == 2) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1]);
                }
                if (dp[i][j] && len > maxlen) {
                    maxlen = len;
                    sp = i;
                }
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         if (j - i + 1 > maxlen) {
        //             if (solve(s, i, j)) {
        //                 maxlen = j - i + 1;
        //                 sp = i;
        //             }
        //         }
        //     }
        // }
        return s.substr(sp, maxlen);
    }
};