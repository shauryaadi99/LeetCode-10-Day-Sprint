class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> lastSkipLength;
        string res;
        for (char& ch : s) {
            if (ch == '(') {
                lastSkipLength.push(res.length());
            } else if (ch == ')') {
                int l = lastSkipLength.top();
                lastSkipLength.pop();
                reverse(begin(res) + l, end(res));
            } else {
                res.push_back(ch);
            }
        }
        return res;
    }
};