class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size(),mx = INT_MIN;
        vector<int> res(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            res[i] = __gcd(nums[i], mx);
        }
        sort(begin(res), end(res));
        bool n_odd = (n % 2 == 0 ? false : true);
        for (int i = 0; i < n / 2; i++) {
            if (i == n / 2 && n_odd)
                continue;
            sum+=__gcd(res[i],res[n-i-1]);
        }
        return sum;
    }
};