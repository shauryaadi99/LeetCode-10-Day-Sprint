class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size(), n = grid[0].size();

        vector<int> res;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res.push_back(grid[i][j]);
            }
        }

        k %= (m * n);

        reverse(res.begin(), res.end());
        reverse(res.begin(), res.begin() + k);
        reverse(res.begin() + k, res.end());

        vector<vector<int>> ans(m, vector<int>(n));

        int h = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = res[h++];
            }
        }

        return ans;
    }
};