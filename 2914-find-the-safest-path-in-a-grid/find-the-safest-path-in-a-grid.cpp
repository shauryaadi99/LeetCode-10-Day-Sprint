class Solution {
public:
    vector<int> rows = {-1, 1, 0, 0};
    vector<int> cols = {0, 0, -1, 1};
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& score, int n) {
        queue<pair<int, int>> q;
        // finding all theives
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    score[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int sc = score[x][y];
            for (int i = 0; i < 4; i++) {
                int newX = x + rows[i];
                int newY = y + cols[i];
                if (newX >= 0 && newX < n && newY >= 0 && newY < n &&
                    score[newX][newY] > sc+1) {
                    score[newX][newY] = 1 + sc;
                    q.push({newX, newY});
                }
            }
        }
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1])
            return 0;
        vector<vector<int>> score(n, vector<int>(n, INT_MAX));
        bfs(grid, score, n);
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({score[0][0], {0, 0}});
        while (!pq.empty()) {
            auto [safe, pos] = pq.top();
            int x = pos.first, y = pos.second;
            pq.pop();
            if (vis[x][y])
                continue;
            vis[x][y] = true;
            if (x == n - 1 && y == n - 1)
                return safe;
            for (int i = 0; i < 4; i++) {
                int newX = x + rows[i];
                int newY = y + cols[i];
                if (newX >= 0 && newX < n && newY >= 0 && newY < n &&
                    !vis[newX][newY]) {
                    int s = min(safe, score[newX][newY]);
                    pq.push({s, {newX, newY}});
                }
            }
        }
        return -1;
    }
};