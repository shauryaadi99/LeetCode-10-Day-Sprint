class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(begin(cost), end(cost));
        int sum = 0, k = 1;
        for (int i = n - 1; i >= 0; i--, k++) {
            if (k % 3 == 0)
                continue;
            sum += cost[i];
        }
        return sum;
    }
};