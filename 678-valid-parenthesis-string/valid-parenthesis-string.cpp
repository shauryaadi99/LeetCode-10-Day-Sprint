class Solution {
public:
    int t[101][101];
    bool solve(int i, string& s, int cnt) {
        bool ans;
        if (i == s.size())
            return (cnt == 0);
        if (cnt < 0)
            return false;
        if (t[i][cnt] != -1)
            return t[i][cnt];

        if (s[i] == '(')
            ans = solve(i + 1, s, cnt + 1);
        else if (s[i] == ')')
            ans = solve(i + 1, s, cnt - 1);
        else {
            bool asSpace = solve(i + 1, s, cnt);
            bool asOpen = solve(i + 1, s, cnt + 1);
            bool asClose = solve(i + 1, s, cnt - 1);
            ans = (asSpace || asOpen || asClose);
        }
        return t[i][cnt] = ans;
    }
    bool checkValidString(string s) {
        int n = s.size();
        // memset(t, -1, sizeof(t));
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int cnt = 0; cnt <= n; cnt++) {
            dp[n][cnt] = (cnt == 0);
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int cnt = 0; cnt <= n; cnt++) {
                if (s[i] == '(') {

                    if (cnt < n) {
                        dp[i][cnt] = dp[i + 1][cnt + 1];
                    }
                } else if (s[i] == ')') {
                    if (cnt > 0)
                        dp[i][cnt] = dp[i + 1][cnt - 1];
                } else {
                    bool asSpace = dp[i + 1][cnt];
                    bool asOpen = false;
                    if (cnt < n) {
                        asOpen = dp[i + 1][cnt + 1];
                    }
                    bool asClose = false;
                    if (cnt > 0)
                        asClose = dp[i + 1][cnt - 1];
                    dp[i][cnt] = asSpace || asOpen || asClose;
                }
            }
        }
        return dp[0][0];

        // return solve(0, s, 0);
    }
};