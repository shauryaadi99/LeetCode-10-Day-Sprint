class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        int i = 0, j = 0;
        while (i < n) {
            if (s[i] == '*') {
                j--;
            } else {
                s[j] = s[i];
                j++;
            }
            i++;
        }
        return s.substr(0, j);
    }
};