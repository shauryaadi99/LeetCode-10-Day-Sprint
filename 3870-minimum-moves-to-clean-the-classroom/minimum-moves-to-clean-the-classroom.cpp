class Solution {
public:
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int startR = 0, startC = 0;
        int litterCount = 0;

        // Find start and count litter
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                }

                if (classroom[r][c] == 'L') {
                    litterCount++;
                }
            }
        }

        // All litter collected
        int fullMask = (1 << litterCount) - 1;

        // Give every litter cell a bit number
        vector<vector<int>> litterId(m, vector<int>(n, -1));

        int id = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (classroom[r][c] == 'L') {
                    litterId[r][c] = id++;
                }
            }
        }

        /*
            State:
            (row, col, currentEnergy, mask)
        */

        queue<tuple<int, int, int, int>> q;

        q.push({startR, startC, energy, 0});

        /*
            visited[row][col][energy][mask]

            energy can be 0...50
            mask can be 0...(2^10 - 1)
        */
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        visited[startR][startC][energy][0] = true;

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            // Process one BFS level
            while (sz--) {

                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == fullMask) {
                    return moves;
                }

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n) {
                        continue;
                    }

                    // Obstacle
                    if (classroom[nr][nc] == 'X') {
                        continue;
                    }

                    // Cannot make a move if energy is already 0
                    if (currEnergy == 0) {
                        continue;
                    }

                    int newEnergy = currEnergy - 1;
                    int newMask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        int litterIndex = litterId[nr][nc];
                        newMask |= (1 << litterIndex);
                    }

                    // Reset energy on R
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // Already visited this exact state
                    if (visited[nr][nc][newEnergy][newMask]) {
                        continue;
                    }

                    visited[nr][nc][newEnergy][newMask] = true;

                    q.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};