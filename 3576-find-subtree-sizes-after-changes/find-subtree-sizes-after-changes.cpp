class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> resultSize;
    vector<int> last;

    void dfs(int currnode, string& s, vector<int>& parent) {
        int c = s[currnode] - 'a';
        int nearestAncestor = last[c];
        last[c] = currnode;

        for (int child : adj[currnode]) {
            dfs(child, s, parent);
        }
        last[c] = nearestAncestor;
        if (currnode != 0) {
            int newParent = parent[currnode];
            if (nearestAncestor != -1) {
                newParent = nearestAncestor;
            }
            parent[currnode] = newParent;
            resultSize[newParent] += resultSize[currnode];
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        for (int i = 1; i < n; i++) {
            int u = parent[i];
            int v = i;
            adj[u].push_back(v);
        }
        resultSize.assign(n, 1);
        last.assign(26, -1);
        dfs(0, s, parent);
        return resultSize;
    }
};