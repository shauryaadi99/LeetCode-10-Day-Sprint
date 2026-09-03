class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int remove = -1; remove < n; remove++) {
            vector<int> arr;
            for (int i = 0; i < n; i++) {
                if (i != remove)
                    arr.push_back(nums[i]);
            }
            int m = arr.size();
            if (m < 2)
                continue;
            vector<int> gcdPref(m);
            vector<int> gcdSuff(m);
            gcdPref[0] = arr[0];
            gcdSuff[m - 1] = arr[m - 1];
            for (int i = 1; i < m; i++) {
                gcdPref[i] = gcd(gcdPref[i-1], arr[i]);
            }
            for (int i = m - 2; i >= 0; i--) {
                gcdSuff[i] = gcd(gcdSuff[i+1], arr[i]);
            }
            int cnt = 0;
            for (int i = 0; i < m - 1; i++) {
                if (gcdPref[i] == gcdSuff[i + 1]) {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};