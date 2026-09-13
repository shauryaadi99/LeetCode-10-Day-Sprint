class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size(), maxi = 0;
        int cnta = 0, cntb = 0;
        vector<pair<int, int>> A, B;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1)
                    A.push_back({i, j});
                if (img2[i][j] == 1)
                    B.push_back({i, j});
            }
        }
        for (auto& a : A) {
            for (auto& b : B) {
                int dx = a.first - b.first;
                int dy = a.second - b.second;
                mp[{dx, dy}]++;
            }
        }
        for (auto& x : mp) {
            maxi = max(maxi, x.second);
        }
        return maxi;
    }
};