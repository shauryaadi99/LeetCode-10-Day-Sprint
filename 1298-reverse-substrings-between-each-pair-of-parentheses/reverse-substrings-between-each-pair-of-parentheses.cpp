class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> openBracketIdx;
        vector<int> door(n);
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(') {
                openBracketIdx.push(i);
            } else if (ch == ')') {
                int j = openBracketIdx.top();
                openBracketIdx.pop();
                door[i] = j;
                door[j] = i;
            }
        }
        int flag = 1;
        string result;
        for (int i = 0; i < n; i += flag) {
            if (s[i] == '(' || s[i] == ')') {
                i = door[i];
                flag = -flag;
            } else {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};