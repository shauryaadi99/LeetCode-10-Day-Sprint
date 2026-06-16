class Solution {
public:
    string processStr(string st) {
        int n = st.size();
        string s = "";
        for (char ch : st) {
            if (isalpha(ch)) {
                s += ch;
            } else if (ch == '#') {
                s += s;
            } else if (ch == '%') {
                reverse(s.begin(), s.end());
            } else if (ch == '*') {
                s = s.substr(0, s.size() - 1);
            }
        }
        return s;
    }
};