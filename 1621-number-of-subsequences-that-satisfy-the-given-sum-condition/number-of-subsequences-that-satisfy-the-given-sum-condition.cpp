class Solution {
public:
    const int mod = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size(), cnt = 0;
        vector<int> pow2(n);

        pow2[0] = 1;

        for (int i = 1; i < n; i++) {
            pow2[i] = (2LL * pow2[i - 1]) % mod;
        }
        sort(begin(nums), end(nums));
        int left = 0, right = n - 1;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                cnt = (cnt + pow2[right - left]) % mod;
                left++;
            } else {
                right--;
            }
        }
        return (cnt % mod);
    }
};