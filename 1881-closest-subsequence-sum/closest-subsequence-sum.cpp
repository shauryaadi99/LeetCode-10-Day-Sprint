class Solution {
public:
    vector<int> nums;
    vector<int> findAllSubsetSums(int n, int offset) {
        vector<int> sums(1 << n);
        for (int mask = 0; mask < (1 << n); mask++) {
            int s = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    s += nums[offset + i];
            }
            sums[mask] = s;
        }
        return sums;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        this->nums = nums;
        int n = nums.size();
        int n1 = n / 2;
        int n2 = n - n1;
        vector<int> sumsA = findAllSubsetSums(n1, 0);
        vector<int> sumsB = findAllSubsetSums(n2, n1);
        sort(begin(sumsB), end(sumsB));
        int minValue = INT_MAX;
        for (int sum1 : sumsA) {
            int need = goal - sum1;
            int lowIdx =
                lower_bound(begin(sumsB), end(sumsB), need) - begin(sumsB);

            if (lowIdx < sumsB.size()) {
                int sum2 = sumsB[lowIdx];
                int total = sum1 + sum2;
                minValue = min(minValue, abs(goal - total));
            }
            if (lowIdx > 0) {
                int sum2 = sumsB[lowIdx - 1];
                int total = sum1 + sum2;
                minValue = min(minValue, abs(goal - total));
            }
        }
        return minValue;
    }
};