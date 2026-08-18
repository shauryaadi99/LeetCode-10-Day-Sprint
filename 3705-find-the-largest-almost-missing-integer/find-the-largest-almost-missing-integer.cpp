class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        int maxEle_freq1 = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (freq[nums[i]] == 1) {
                maxEle_freq1 = max(maxEle_freq1, nums[i]);
            }
        }

        if (k == 1) {
            if (maxEle_freq1 == INT_MIN)
                return -1;
            return maxEle_freq1;
        }
        if (n == k)
            return *max_element(begin(nums), end(nums));

        if (freq[nums[0]] == 1 && freq[nums[n - 1]] == 1) {
            return max(nums[0], nums[n - 1]);
        } else if (freq[nums[0]] != 1 && freq[nums[n - 1]] != 1)
            return -1;
        else {
            return (freq[nums[0]] == 1 ? nums[0] : nums[n - 1]);
        }
        return -1;
    }
};