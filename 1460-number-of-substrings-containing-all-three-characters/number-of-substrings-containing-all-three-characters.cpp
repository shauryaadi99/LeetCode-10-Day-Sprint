class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), res = 0,l=0;
        int cnta = 0, cntb = 0, cntc = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                cnta++;
            else if (s[i] == 'b')
                cntb++;
            else if (s[i] == 'c')
                cntc++;
            while (cnta > 0 && cntb > 0 && cntc > 0) {
                res += n - i;
                if (s[l] == 'a')
                    cnta--;
                else if (s[l] == 'b')
                    cntb--;
                else if (s[l] == 'c')
                    cntc--;
                l++;
            }
        }
        return res;
    }
};