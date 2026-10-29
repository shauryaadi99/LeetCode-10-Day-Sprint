class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int S = accumulate(begin(nums), end(nums), 0);
        int n = N / 2;
        unordered_map<int, vector<int>> sumLeft;
        unordered_map<int, vector<int>> sumRight;
        for (int mask = 0; mask <= (1 << n); mask++) {
            int count = 0;
            int sumL = 0, sumR = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    sumL += nums[i];
                    sumR += nums[n + i];
                    count++;
                }
            }
            sumLeft[count].push_back(sumL);
            sumRight[count].push_back(sumR);
        }
        for (int count = 0; count <= n; count++) {
            sort(begin(sumRight[count]), end(sumRight[count]));
        }
        int minValue = INT_MAX;
        for (int k = 0; k <= n; k++) {
            int m = n - k;
            for (int leftSum : sumLeft[k]) {
                int need = (S - 2 * leftSum) / 2;
                int lowIdx =
                    lower_bound(begin(sumRight[m]), end(sumRight[m]), need) -
                    begin(sumRight[m]);
                if (lowIdx < sumRight[m].size()) {
                    int rightSum = sumRight[m][lowIdx];
                    minValue = min(minValue, abs(2 * (leftSum + rightSum) - S));
                }
                if (lowIdx - 1 >= 0) {
                    int rightSum = sumRight[m][lowIdx - 1];
                    minValue = min(minValue, abs(2 * (leftSum + rightSum) - S));
                }
            }
        }
        return minValue;
    }
};