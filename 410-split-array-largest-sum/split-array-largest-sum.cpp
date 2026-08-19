class Solution {
public:
    int k;
    bool isPossible(vector<int>& nums, int mid) {
        int n = nums.size(), cnt = 1, sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] > mid) {
                cnt++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        this->k = k;
        int low = *max_element(begin(nums), end(nums)),
            high = accumulate(begin(nums), end(nums), 0);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(nums, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};