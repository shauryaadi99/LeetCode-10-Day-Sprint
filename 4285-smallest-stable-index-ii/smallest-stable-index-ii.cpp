class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preMax(n), suffMin(n);
        preMax[0] = nums[0];
        suffMin[n - 1] = nums[n - 1];
        int ans = INT_MAX;
        for (int i = 1; i < n; i++) {
            preMax[i] = max(nums[i], preMax[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }
        for (int i = 0; i < n; i++) {
            int x = preMax[i] - suffMin[i];
            if (x <= k) {
                ans = min(i, ans);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};