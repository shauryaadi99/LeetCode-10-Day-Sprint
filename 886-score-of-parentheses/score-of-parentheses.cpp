class Solution {
public:
    int scoreOfParentheses(string s) {
        int cnt = 0, n = s.size(), score = 0;
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                vec.push_back(score);
                score = 0;
            } else {
                if (s[i - 1] == '(') {
                    score = vec.back() + 1;
                } else {
                    score = vec.back() + 2 * score;
                }
                vec.pop_back();
            }
        }
        return score;
    }
};