class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, int> freq;
        for (auto& x : nums)
            freq[x]++;
        int ans = 1;
        if (freq.count(1))
            ans = max(ans, (freq[1] % 2 == 0 ? freq[1] - 1 : freq[1]));

        for (auto [num, f] : freq) {
            if (num == 1)
                continue;
            int len = 0;
            long long x = num;
            while (freq.count(x) && freq[x] >= 2) {
                len += 2;
                if (x > 1e9)
                    break;
                x *= x;
            }
            if (freq.count(x))
                len++;
            else
                len--;
            ans = max(ans, len);
        }
        return ans;
    }
};