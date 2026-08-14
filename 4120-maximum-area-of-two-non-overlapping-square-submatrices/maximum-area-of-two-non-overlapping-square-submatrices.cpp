class Solution {
public:

    bool can(vector<vector<int>>& mat,
             vector<vector<int>>& pref,
             int k) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> valid(m, vector<int>(n, 0));

        for (int r = 0; r + k <= m; r++) {
            for (int c = 0; c + k <= n; c++) {

                int ones = pref[r + k][c + k]
                         - pref[r][c + k]
                         - pref[r + k][c]
                         + pref[r][c];

                if (ones == k * k) {
                    valid[r][c] = 1;
                }
            }
        }

        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);

        for (int r = 0; r + k <= m; r++) {
            for (int c = 0; c + k <= n; c++) {
                if (valid[r][c]) {
                    rowCount[r]++;
                    colCount[c]++;
                }
            }
        }

        vector<int> rowPref(m + 1, 0);
        vector<int> colPref(n + 1, 0);

        for (int r = 0; r < m; r++) {
            rowPref[r + 1] = rowPref[r] + rowCount[r];
        }

        for (int c = 0; c < n; c++) {
            colPref[c + 1] = colPref[c] + colCount[c];
        }

        for (int r = 0; r + k <= m; r++) {
            for (int c = 0; c + k <= n; c++) {

                if (!valid[r][c])
                    continue;

                // Another square completely above
                if (r >= k && rowPref[r - k + 1] > 0) {
                    return true;
                }

                // Another square completely to the left
                if (c >= k && colPref[c - k + 1] > 0) {
                    return true;
                }
            }
        }

        return false;
    }

    int maxArea(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> pref(m + 1,
                                  vector<int>(n + 1, 0));

        // 2D prefix sum
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                pref[r + 1][c + 1] =
                    mat[r][c]
                    + pref[r][c + 1]
                    + pref[r + 1][c]
                    - pref[r][c];
            }
        }

        int low = 1;
        int high = min(m, n);
        int ans = 0;

        // Binary search for maximum side length
        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (can(mat, pref, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans * ans;
    }
};