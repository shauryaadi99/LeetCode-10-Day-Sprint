class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& it : times) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }
        // {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        // Distance array
        vector<int> dist(n + 1, INT_MAX);
        pq.push({0, k});
        dist[k] = 0;
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (d > dist[node])
                continue;
            for (auto it : adj[node]) {
                int w = it.second;
                int adjNode = it.first;
                if (d + w < dist[adjNode]) {

                    dist[adjNode] = d + w;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};