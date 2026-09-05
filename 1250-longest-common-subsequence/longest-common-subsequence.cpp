class Solution {
public:
    int t[1001][1001];
    int solve(int i, int j, string& s1, string& s2) {
        if (i < 0 || j < 0)
            return 0;
        if (t[i][j] != -1)
            return t[i][j];
        if (s1[i] == s2[j])
            return t[i][j] = 1 + solve(i - 1, j - 1, s1, s2);
        return t[i][j] = max(solve(i - 1, j, s1, s2), solve(i, j - 1, s1, s2));
    }
    int longestCommonSubsequence(string s1, string s2) {
        memset(t,-1,sizeof(t));
        return solve(s1.size() - 1, s2.size() - 1, s1, s2);
    }
};