class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        unordered_map<int, vector<int>> children;
        for (int i = 1; i < parent.size(); i++) {
            children[parent[i]].push_back(i);
        }
        int n = nums.size();
        vector<int> depth(n, 0);
        int height = 0;
        stack<pair<int, int>> st;
        st.push({0, 1}); //{node,depth}
        while (!st.empty()) {
            auto [node, d] = st.top();
            st.pop();
            depth[node] = d;
            height = max(height, d);
            for (auto& n : children[node]) {
                st.push({n, d + 1});
            }
        }
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += 1LL * nums[i] * (height - depth[i] + 1);
        }
        return sum;
    }
};