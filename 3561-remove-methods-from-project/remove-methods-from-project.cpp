class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);
        for (vector<int> vec : invocations) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<bool> suspicious(n, false);
        // bfs traversal
        queue<int> q;
        q.push(k);
        suspicious[k] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int& ngbr : adj[node]) {
                indegree[ngbr]--;
                if (!suspicious[ngbr]) {
                    suspicious[ngbr] = true;
                    q.push(ngbr);
                }
            }
        }
        vector<int> res;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (suspicious[i] == true && indegree[i] > 0) {
                flag = true;
                break;
            }
            if (!suspicious[i]) {
                res.push_back(i);
            }
        }
        vector<int> orig;
        if (flag) {
            for (int i = 0; i < n; i++)
                orig.push_back(i);
            return orig;
        }
        return res;
    }
};