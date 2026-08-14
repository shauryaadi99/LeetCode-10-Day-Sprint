class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long maxi = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long GCD = __gcd(nums[i], nums[j]);
                GCD = GCD * GCD;
                long long val = 1LL * nums[i] * nums[j] / GCD;
                maxi = max(val, maxi);
            }
        }
        return maxi;
    }
};