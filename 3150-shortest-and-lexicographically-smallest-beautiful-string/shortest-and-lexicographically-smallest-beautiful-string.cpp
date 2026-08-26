class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0;
        int cnt1 = 0;
        string ans = "";
        for (int r = 0; r < n; r++) {

            if (s[r] == '1')
                cnt1++;

            int sz = r - l + 1;
            while (cnt1 > k) {
                if (s[l] == '1')
                    cnt1--;
                l++;
            }
            if (cnt1 == k) {
                while (s[l] == '0') {
                    l++;
                }
                sz = r - l + 1;
                if (ans == "" || sz < ans.size() ||
                    (sz == ans.size() && s.substr(l, sz) < ans))
                    ans = s.substr(l, sz);
            }
        }

        return ans;
    }
};