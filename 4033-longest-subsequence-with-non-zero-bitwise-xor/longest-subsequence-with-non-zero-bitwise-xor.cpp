class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xor_all = 0;
        bool allzero = true;
        for (int x : nums) {
            xor_all ^= x;
            if (x != 0)
                allzero = false;
        }
        if (allzero)
            return 0;

        if (xor_all)
            return n;

        return n - 1;
    }
};