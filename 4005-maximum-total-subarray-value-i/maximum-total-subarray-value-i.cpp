class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi = *max_element(begin(nums), end(nums)),
            mini = *min_element(begin(nums), end(nums));
        long long ans = k * (maxi - mini);
        return ans;
    }
};