class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                continue;

            int l = i;

            long long sum = 0;

            while (i < n && s[i] == '1') {
                sum += nums[i];
                i++;
            }

            int r = i - 1;

            if (l == 0) {
                ans += sum;
            } else {
                int mini = nums[l - 1];
                long long blockSum = nums[l - 1];

                for (int j = l; j <= r; j++) {
                    blockSum += nums[j];
                    mini = min(mini, nums[j]);
                }

                ans += blockSum - mini;
            }

            i--; 
        }
        return ans;
    }
};