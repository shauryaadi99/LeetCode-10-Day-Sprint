class Solution {
public:
    int longestValidParentheses(string s) {
        int cnt = 0;
        int n = s.size(), result = 0;
        // from left to right
        int open = 0, close = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                open++;
            else
                close++;
            if (close > open) {
                open = close = 0;
            } else if (open == close) {
                result = max(result, open + close);
            }
        }
        // from right to left
        open = 0, close = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(')
                open++;
            else
                close++;
            if (open > close) {
                open = close = 0;
            } else if (open == close) {
                result = max(result, open + close);
            }
        }
        return result;
    }
};