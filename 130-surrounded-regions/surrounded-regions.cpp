class Solution {
public:
    int n;
    int m;
    vector<vector<int>> visited;
    vector<vector<char>> board;
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};

    void dfs(int i, int j) {
        visited[i][j] = 1;
        for (int r = 0; r < 4; r++) {
            int nrow = i + drow[r];
            int ncol = j + dcol[r];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                visited[nrow][ncol] != 1 && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        this->m = board.size();    // rows
        this->n = board[0].size(); // columns
        visited.assign(m, vector<int>(n, 0));
        this->board = board;
        // first and last column
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(i, 0);
            }
            if (board[i][n - 1] == 'O') {
                dfs(i, n - 1);
            }
        }
        // first and last row
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                dfs(0, j);
            }
            if (board[m - 1][j] == 'O') {
                dfs(m - 1, j);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && visited[i][j] == 0)
                    board[i][j] = 'X';
            }
        }
    }
};