class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        double ans = 0;
        int k = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            int p = prices[i];
            int d = (k < discounts.size() ? discounts[k] : 0);
            ans += (p * (100 - d)) / 100.0;
            k++;
        }
        return ans;
    }
};