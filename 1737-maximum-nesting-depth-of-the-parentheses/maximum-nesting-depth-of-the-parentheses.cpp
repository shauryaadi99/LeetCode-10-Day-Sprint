class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int cnt = 0, ans = 0;
        for (char ch : s) {
            ans = max(ans, cnt);
            if (ch == '(')
                cnt++;
            else if (ch == ')')
                cnt--;
        }
        return ans;
    }
};