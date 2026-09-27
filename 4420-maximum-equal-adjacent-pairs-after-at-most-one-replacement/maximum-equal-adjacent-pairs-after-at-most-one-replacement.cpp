class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        // first baseline counting
        int baseline = 0;
        for (int i = 0; i < n - 1; i++) {
            int x = nums[i];
            int y = nums[i + 1];
            if (x == y) {
                baseline++;
            }
        }
        unordered_map<int, unordered_map<int, int>> mp;
        for (int i = 0; i < n - 1; i++) {
            int a = nums[i];
            int b = nums[i + 1];
            mp[a][b]++;
        }
        int maxi = 0 ;
        for (int i = 0; i < n - 1; i++) {
            int a = nums[i];
            int b = nums[i + 1];
            if (a == b)
                continue;
            int gain = mp[a][b] + mp[b][a];
            maxi = max(maxi, gain);
        }
        return maxi + baseline;
    }
};