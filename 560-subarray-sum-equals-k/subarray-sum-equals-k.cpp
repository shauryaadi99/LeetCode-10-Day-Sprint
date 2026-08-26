class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0, currsum = 0;
        for (int i = 0; i < n; i++) {
            currsum += nums[i];
            if (mp.count(currsum - k)) {
                res += mp[currsum - k];
            }
            mp[currsum]++;
        }
        return res;
    }
};