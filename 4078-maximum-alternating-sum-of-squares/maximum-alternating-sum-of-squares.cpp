class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums),
             [](auto& a, auto& b) { return abs(a) < abs(b); });
        long long sum = 0, cnt = 0;
        cnt = (n+1)/2;
        for (int i = n - 1; i >= n-cnt; i--) {
            sum += 1LL*(nums[i] * nums[i]);
        }
        for (int i = n-cnt-1
        ; i >= 0; i--) {
            sum -= 1LL*(nums[i] * nums[i]);
        }
        return sum;
    }
};