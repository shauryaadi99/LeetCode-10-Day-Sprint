class Solution {
public:
    int dx[4] = {1, 1, -1, -1};
    int dy[4] = {1, -1, 1, -1};
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        vector<vector<bool>> visited(9, vector<bool>(9, false));
        queue<pair<pair<int, int>, int>> q;
        q.push({{source[0], source[1]}, 0});
        visited[source[0]][source[1]] = true;
        while (!q.empty()) {
            auto& [x, y] = q.front().first;
            int steps = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                while (nx > 0 && nx <= 8 && ny > 0 && ny <= 8) {
                    if (!visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push({{nx, ny}, steps + 1});
                    }
                    nx += dx[i];
                    ny += dy[i];
                }
            }

            if (x == target[0] && y == target[1])
                return steps;
        }
        return -1;
    }
};