class Solution {
public:
    void solve(int i, int prev, vector<int>& nums, vector<int>& result,
               vector<int>& temp) {
        if (i >= nums.size()) {
            if (result.size() < temp.size())
                result = temp;
            return;
        }

        if (prev == -1 || nums[i] % nums[prev] == 0) {
            temp.push_back(nums[i]); // for take
            solve(i + 1, i, nums, result, temp);
            temp.pop_back(); // for nottake
        }

        solve(i + 1, prev, nums, result, temp);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int idx = 0;
        int maxLen = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
                idx = i;
            }
        }
        vector<int> res;

        while (idx != -1) {
            res.push_back(nums[idx]);
            idx = prev[idx];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};