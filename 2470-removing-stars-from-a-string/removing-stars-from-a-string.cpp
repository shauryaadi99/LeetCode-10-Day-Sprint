class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        stack<char> st;
        for (char ch : s) {
            if (ch == '*') {
                st.pop();
                continue;
            }
            st.push(ch);
        }
        string str = "";
        while (!st.empty()) {
            char ch = st.top();
            st.pop();

            str += ch;
        }
        reverse(begin(str), end(str));
        return str;
    }
};