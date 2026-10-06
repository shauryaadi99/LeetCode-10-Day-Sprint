class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int ans = 0, balance = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                balance++;
            else {
                if (balance > 0)
                    balance--;
                else {
                    ans++;
                }
            }
        }
        return ans + balance;
    }
};