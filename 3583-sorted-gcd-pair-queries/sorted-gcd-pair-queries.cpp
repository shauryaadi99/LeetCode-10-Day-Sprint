class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // freq[x] = occurrences of x
        vector<long long> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;

        // cnt[d] = numbers divisible by d
        vector<long long> cnt(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            for (int multiple = d; multiple <= mx; multiple += d)
                cnt[d] += freq[multiple];
        }

        // exactPairs[g] = pairs whose gcd is exactly g
        vector<long long> exactPairs(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            exactPairs[g] = cnt[g] * (cnt[g] - 1) / 2;

            for (int multiple = 2 * g; multiple <= mx; multiple += g)
                exactPairs[g] -= exactPairs[multiple];
        }

        // Prefix sums over gcd values
        vector<long long> prefix(mx + 1, 0);
        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exactPairs[g];

        vector<int> ans;

        for (long long q : queries) {
            // q is 0-indexed
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};