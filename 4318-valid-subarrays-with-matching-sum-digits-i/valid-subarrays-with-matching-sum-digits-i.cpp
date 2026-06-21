class Solution {
public:
    bool check(long long sum, int x) {
        if (sum % 10 != x)
            return false; // last digit

        while (sum >= 10)
            sum /= 10; // first digit

        return sum == x;
    }

    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        long long sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                // string s = to_string(sum);
                if (check(sum, x))
                    cnt++;
            }
        }
        return cnt;
    }
};