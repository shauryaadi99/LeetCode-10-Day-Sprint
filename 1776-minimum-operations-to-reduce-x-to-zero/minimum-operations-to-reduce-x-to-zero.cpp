class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int tot_sum = accumulate(begin(nums), end(nums), 0);
        int final_sum = tot_sum - x;
        int len = 0, currsum = 0, l = 0;
        for (int r = 0; r < n; r++) {
            currsum += nums[r];
            while (currsum > final_sum && l < n) {
                currsum -= nums[l];
                l++;
            }
            if (currsum == final_sum)
                len = max(len, r - l + 1);
        }
        return (final_sum == 0 || len > 0 ? n - len : -1);
    }
};