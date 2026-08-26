class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), mini = prices[0], profit = 0;
        for (int i = 1; i < n; i++) {
            mini = min(mini, prices[i]);
            profit = max(profit, prices[i] - mini);
        }
        return profit;
    }
};