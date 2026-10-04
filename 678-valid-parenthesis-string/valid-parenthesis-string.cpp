class Solution {
public:
    int t[101][101];
    bool solve(int i, string& s, int cnt) {
        bool ans;
        if (i == s.size())
            return  (cnt == 0);
        if (cnt < 0)
            return  false;
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
        memset(t, -1, sizeof(t));
        return solve(0, s, 0);
    }
};