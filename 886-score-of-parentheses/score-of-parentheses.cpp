class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size(), depth = 0, score = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                if (s[i - 1] == '(') {
                    score += (1 << depth);
                }
            }
        }
        return score;
    }
};