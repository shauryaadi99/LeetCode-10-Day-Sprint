class Solution {
public:
    const int mod = 1e9 + 7;
    long long pow(long long a, long long n) {
        long long res = 1;
        a%=mod;
        while (n > 0) {
            if (n & 1)
                res =  (res*a)%mod;

            a =  (a*a)%mod ;
            n >>= 1;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<pair<int, int>> q;
        q.push(make_pair(1, 0));
        vector<bool> vis(n + 1, false);
        vis[1] = true;
        int maxDepth = 0;
        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();
            maxDepth = max(maxDepth, depth);
            for (auto& N : adj[node]) {
                if (!vis[N]) {
                    vis[N] = true;
                    q.push({N, depth + 1});
                }
            }
        }
        int ans = (int)pow(2, maxDepth - 1);
        return ans;
    }
};