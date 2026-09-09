class Solution {
public:
    // int solve(int i, int prev) {
    //     if (i < 0)
    //         return 0;
    //     int len = solve(i + 1, prev, nums);
    //     int take;
    //     if (prev == -1 || nums[i] > nums[prev]) {
    //         take = 1 + solve(i + 1, i, nums);
    //         len = max(len, take);
    //     }
    //     return len;
    // }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        // forward lcs
        vector<int> LIS(n, 1);
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i]) {
                    LIS[i] = max(LIS[i], LIS[prev] + 1);
                }
            }
        }
        vector<int> LDS(n, 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int next = i + 1; next < n; next++) {
                if (nums[i] > nums[next]) {
                    LDS[i] = max(LDS[i], LDS[next] + 1);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (LIS[i] > 1 && LDS[i] > 1) {

                int mountainlen = LIS[i] + LDS[i] - 1;
                res = max(res, mountainlen);
            }
        }
        return n - res;
    }
};