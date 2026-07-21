class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> res;
        int cnt = 0, maxi = 0, ones = 0;

        for (char ch : s) {
            if (ch == '1') {
                ones++;
                if (cnt > 0)
                    res.push_back(cnt);
                cnt = 0;
            } else
                cnt++;
        }
        if (cnt > 0)
            res.push_back(cnt);
            if(res.size()>1)
        for (int i = 0; i < res.size() - 1; i++) {
            maxi = max(maxi, res[i] + res[i + 1]);
        }
        return maxi + ones;
    }
};