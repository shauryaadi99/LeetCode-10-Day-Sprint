class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0;
        int cnt1 = 0;
        string ans = "";

        for (int r = 0; r < n; r++) {

            // Add s[r]
            if (s[r] == '1')
                cnt1++;

            // Too many 1s
            while (cnt1 > k) {
                if (s[l] == '1')
                    cnt1--;
                l++;
            }

            // Exactly k 1s
            if (cnt1 == k) {

                // Remove unnecessary leading zeroes
                while (s[l] == '0')
                    l++;

                int sz = r - l + 1;
                string cur = s.substr(l, sz);

                // Shorter is better.
                // If same length, lexicographically smaller is better.
                if (ans == "" ||
                    sz < ans.size() ||
                    (sz == ans.size() && cur < ans)) {
                    ans = cur;
                }
            }
        }

        return ans;
    }
};
