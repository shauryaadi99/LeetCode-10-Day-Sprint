class Solution {
public:
    char processStr(string s, long long k) {
        // Forward pass: compute final string length
        long long len = 0;

        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                len++;
            } else if (ch == '#') {
                len *= 2;
            } else if (ch == '*') {
                if (len > 0) {
                    len--;
                }
            }
            // '%' does not change length
        }

        // k is 0-indexed
        if (k >= len) {
            return '.';
        }

        // Backward pass
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            char ch = s[i];

            if (ch == '*') {
                // Undo deletion
                len++;
            } 
            else if (ch == '#') {
                // Undo duplication
                len /= 2;
                if (k >= len) {
                    k -= len;
                }
            } 
            else if (ch == '%') {
                // Undo reversal
                k = len - 1 - k;
            } 
            else { // letter
                len--;
                if (len == k) {
                    return ch;
                }
            }
        }

        return '.';
    }
};