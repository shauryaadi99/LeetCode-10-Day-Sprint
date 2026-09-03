class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = nums1[0], n = nums1.size(), cntOdd = 0;
        for (int i = 0; i < n; i++) {
            mini = min(mini, nums1[i]);
            nums1[i] & 1 ? cntOdd++ : 0;
        }
        return (mini & 1 || cntOdd == 0);
    }
};