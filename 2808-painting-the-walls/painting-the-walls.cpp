class Solution {
public:
    const int INF = 1e9;
    int t[501][501];
    int solve(int i, int remain, vector<int>& cost, vector<int>& time, int n) {
        if (remain <= 0) {
            return 0;
        }

        if (i >= n) {
            return INF;
        }
        if (t[i][remain] != -1)
            return t[i][remain];
        int take, nottake;
        take = cost[i] + solve(i + 1, remain - 1 - time[i], cost, time, n);
        nottake = solve(i + 1, remain, cost, time, n);
        return t[i][remain] = min(take, nottake);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        memset(t, -1, sizeof(t));
        return solve(0, n, cost, time, n);
    }
};